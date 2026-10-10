#!/usr/bin/env python3
"""history_audit.py — the visibility gate: no game-derived byte anywhere in git history, not only the tip.

    tools/publish/history_audit.py              # audit every blob reachable from local refs + origin's advertised refs
    tools/publish/history_audit.py --selftest   # scratch repo under .run/: the fixture blob is caught, a clean blob passes

Every reachable blob is written to .run/hist/<blob id> (git cat-file --batch) and run through
`tools/audit_public.py --paths` (content hash, size, disassembly runs); every path ever named in history is checked
against the same purge/glob rules (audit_public.under_rules). Remote tips missing locally (e.g. refs/pull/*) are
fetched read-only into refs/audit/* and deleted after. Forced updates: reflog entries of main and origin/main whose
old value is not an ancestor of the new one, plus remote tips not an ancestor of any local ref.
Exit 0 only with 0 offenders. Output: docs/publish/visibility.md records the real run.
"""
import pathlib
import shutil
import subprocess
import sys

REPO = pathlib.Path(__file__).resolve().parents[2]
PY = sys.executable
HIST = REPO / ".run" / "hist"
ARGV_CAP = 100_000                # chars of paths per audit_public invocation
sys.path.insert(0, str(REPO / "tools"))
import audit_public  # noqa: E402  (read_config, under_rules only; its main() is never imported-run)


def git(repo, *args, check=True, inp=None):
    r = subprocess.run(["git", *args], cwd=repo, input=inp, capture_output=True, check=False)
    if check and r.returncode:
        sys.exit(f"history_audit: git {' '.join(args)}: {r.stderr.decode(errors='replace').strip()}")
    return r


def out(repo, *args):
    return git(repo, *args).stdout.decode("utf-8", "surrogateescape")


def is_ancestor(repo, a, b):
    return git(repo, "merge-base", "--is-ancestor", a, b, check=False).returncode == 0


def has_object(repo, sha):
    return git(repo, "cat-file", "-e", f"{sha}^{{commit}}", check=False).returncode == 0


def remote_refs(repo):
    if git(repo, "remote", "get-url", "origin", check=False).returncode:
        return []
    return [tuple(l.split("\t")) for l in out(repo, "ls-remote", "origin").splitlines() if l]


def local_refs(repo):
    return [r for r in out(repo, "for-each-ref", "--format=%(refname)").split() if not r.startswith("refs/audit/")]


def reflog_rewinds(repo, ref):
    if git(repo, "rev-parse", "--verify", "-q", ref, check=False).returncode:
        return 0
    shas = out(repo, "log", "-g", "--format=%H", ref).split()        # newest first
    return sum(1 for new, old in zip(shas, shas[1:]) if old != new and not is_ancestor(repo, old, new))


def audit(repo):
    """Returns (offenders, summary lines). Offenders are 'OFFENDER <blob|path>: why' strings."""
    remotes = remote_refs(repo)
    fetched = []
    try:
        for i, (sha, name) in enumerate(remotes):
            if not has_object(repo, sha):                             # refs/pull/* or a stale remote head
                dst = f"refs/audit/{i}"
                git(repo, "fetch", "--no-tags", "origin", f"+{name}:{dst}")
                fetched.append(dst)
        locals_ = local_refs(repo)
        tips_off = sum(1 for sha, _ in remotes if not any(is_ancestor(repo, sha, r) for r in locals_))
        rewinds = {r: reflog_rewinds(repo, r) for r in ("refs/heads/main", "refs/remotes/origin/main")}
        n_commits = int(out(repo, "rev-list", "--all", "--count"))
        objs = out(repo, "rev-list", "--objects", "--all").splitlines()
        ids = [l.split(" ", 1)[0] for l in objs]
        types = git(repo, "cat-file", "--batch-check=%(objecttype) %(objectname)",
                    inp="\n".join(ids).encode()).stdout.decode().splitlines()
        blobs = sorted({t.split()[1] for t in types if t.startswith("blob ")})
        paths = set(out(repo, "log", "--all", "--format=", "--name-only", "--no-renames", "-z").split("\0")) - {""}
    finally:
        for dst in fetched:
            git(repo, "update-ref", "-d", dst, check=False)

    offenders = []
    prefixes, globs, *_ = audit_public.read_config()
    for p in sorted(paths):
        rule = audit_public.under_rules(p, prefixes, globs)
        if rule:
            offenders.append(f"OFFENDER path {p}: purge path ({rule})")

    shutil.rmtree(HIST, ignore_errors=True)
    HIST.mkdir(parents=True)
    batch = git(repo, "cat-file", "--batch", inp="\n".join(blobs).encode()).stdout
    pos = 0
    for b in blobs:                                                    # "<id> blob <size>\n<bytes>\n"
        nl = batch.index(b"\n", pos)
        oid, _, size = batch[pos:nl].decode().split()
        assert oid == b, (oid, b)
        (HIST / oid).write_bytes(batch[nl + 1:nl + 1 + int(size)])
        pos = nl + 1 + int(size) + 1
    rels = [f".run/hist/{b}" for b in blobs]
    chunk, size = [], 0
    for rel in rels + [None]:
        if rel is not None and size + len(rel) + 1 <= ARGV_CAP:
            chunk.append(rel); size += len(rel) + 1
            continue
        if chunk:
            r = subprocess.run([PY, str(REPO / "tools" / "audit_public.py"), "--paths", *chunk], cwd=REPO,
                               capture_output=True, text=True)
            hits = [l.strip() for l in r.stdout.splitlines() if l.strip().startswith("OFFENDER ")]
            if r.returncode not in (0, 1) or (r.returncode == 1 and not hits):
                sys.exit(f"history_audit: audit_public exit {r.returncode}: {(r.stderr or r.stdout).strip()[-400:]}")
            offenders += [h.replace("OFFENDER .run/hist/", "OFFENDER blob ", 1) for h in hits]
        chunk, size = ([rel], len(rel) + 1) if rel else ([], 0)
    n_forced = sum(rewinds.values()) + tips_off
    lines = [f"forced-updates: {n_forced} (reflog main {rewinds['refs/heads/main']}, "
             f"origin/main {rewinds['refs/remotes/origin/main']}; remote tips not in local history {tips_off})",
             f"remote refs: {', '.join(n for _, n in remotes) or 'none'}",
             f"history: {len(blobs)} blobs over {n_commits} commits, {len(remotes)} remote refs, "
             f"{len(offenders)} offenders"]
    return offenders, lines


def selftest():
    scratch = REPO / ".run" / "history_audit-selftest"
    shutil.rmtree(scratch, ignore_errors=True)
    scratch.mkdir(parents=True)
    g = ("-c", "user.name=selftest", "-c", "user.email=selftest@invalid", "-c", "commit.gpgsign=false")
    git(scratch, "init", "-q", "-b", "main")
    (scratch / "clean.txt").write_text("a clean blob\n")
    git(scratch, *g, "add", "clean.txt"); git(scratch, *g, "commit", "-qm", "clean")
    off, lines = audit(scratch)
    assert not off and lines[-1].endswith(", 0 offenders"), (off, lines)
    (scratch / "fixture.bin").write_bytes(b"DECOMP-FIXTURE!!")       # the Makefile firewall-check control, not game bytes
    git(scratch, *g, "add", "fixture.bin"); git(scratch, *g, "commit", "-qm", "fixture")
    git(scratch, *g, "rm", "-q", "fixture.bin"); git(scratch, *g, "commit", "-qm", "drop")  # only history holds it now
    off, lines = audit(scratch)
    assert len(off) == 1 and "game-derived content" in off[0], (off, lines)
    shutil.rmtree(scratch)
    print("history_audit: selftest OK (clean blob passes; fixture blob in history caught)")
    return 0


def main(argv):
    if "--selftest" in argv:
        return selftest()
    offenders, lines = audit(REPO)
    for o in offenders:
        print(f"  {o}")
    print("\n".join(lines))
    return 1 if offenders else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
