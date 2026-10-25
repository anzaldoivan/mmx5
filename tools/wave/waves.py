#!/usr/bin/env python3
"""Wave tool: draw a stratified wave of drafting targets, build one card pack per target, try one draft.

  waves.py draw W<k> [--per 6] [--buckets 20,50,100,200] [--order strata|leverage|port-x6] [--size N] [--only A,B] [--per-cluster N]
  waves.py open [--check] [--buckets 20,50,100,200] <L,L,...>
  waves.py card W<k>
  waves.py try <draft.c> --target <alias>_<name>
  waves.py status [W<k>] [--drafts-only] [--waves DIR]
  waves.py rate [W<k>] [--check]
  waves.py port W<k> [--target <alias>_<name>] [--waves DIR]
  waves.py seed W<k> [--target <alias>_<name>] [--waves DIR]
  waves.py --selftest

draw: inputs .run/census/inventory.jsonl, .run/census/groups.jsonl, .run/sig/twins.jsonl, .run/dedup/draw.jsonl
  (never refreshed here; refused, exit 1, when any is older than the last commit touching src or config/splat.*, G31).
  Buckets A..D by insns upper bound; > last bound = lane `unmeasured`, not drawn. Per bucket `--per` targets by draw
  rank, >= 2 rockx5 and >= 3 slus (unsatisfiable -> exit 1 naming the bucket). A candidate is valid when: draw.jsonl
  verdict `draw`, its asm .s on disk, inventory status `asm`, not in config/dedup.exclude.yaml, and no drawn target
  shares its cluster (same groups.jsonl group or a twins.jsonl pair, keyed (alias, name); C0043).
  Writes waves/W<k>/wave.json {wave, date, buckets, targets: [{alias, module, name, vram, insns, bucket, rank, reach}]}
  (never overwrites), re-validates it: `wave: W<k> drew <n> targets, <i> invalid` (exit 1 if i > 0), then
  `lane: <lane> <count>` lines partitioning every draw.jsonl row. --order strata (default) is the above.
  --order leverage --size N (R2): one pool of valid drawable rows by reach desc, insns desc, (alias, vram); a row whose
  bucket (`>`+last bound past it) routes `defer` in docs/routing.md is skipped, `draft-twin` only with a banked twin,
  an X6 lead or a matched lever (as the card computes); NEED is a floor over the N; same wave.json shape, output and
  checks. --order port-x6 --size N: the leverage pool with the rows that have an X6 lead (docs/oracle/x6-leads.tsv)
  first; a lead row is drawn whatever its bucket's route. A target in the ledger (ledger.collect: tried, not banked,
  not c) is invalid `ledgered` in every order and in the re-validation. --only A,B (leverage/port-x6): only pool rows
  whose bucket is named; short of --size -> NEED floor off, the whole valid pool, `wave: pool exhausted, drew <n> of
  --size <N>` when n < N (n == 0: nothing written, exit 1). --per-cluster N (with --only; default 1): up to N
  targets share one cluster; for the A/B tail only, where the open rows sit in one dup cluster (3.3 T43).
open: per named bucket (A..D or `>`+last bound) `open: <L> <o> open, <d> drawable, <l> ledgered[, <u> unranked]` (d = draw.jsonl verdict `draw`
  rows in L, l = those ledgered, o = d - l, u = open rows with rank null, printed when > 0). Stale inputs refused as
  draw. --check: exit 1 if any named bucket has o > 0.
card: .run/wave/W<k>/packs/<alias>_<name>/{card.md, target.s -> asm file}. No asm text in card.md. A card naming a
  lever id or C<nnnn> that resolves in neither docs/codegen-map/levers.yaml nor cookbook/INDEX.md is refused (G44).
  `## Twin in X6`: the target's row of docs/oracle/x6-leads.tsv (X6 function, its C under refs/mmx6/, the map
  X6 name -> X5 name), else `none`.
try: compile the draft standalone (probe.compile_obj, reconcile.triple(); scratch .run/probe/wave/<alias>_<name>/),
  masked word compare (probe.read_func/diff_words) against probe.target_bytes. `try: <name> match` (exit 0) |
  `try: <name> diff <d> of <w> words` (exit 1) + `try:   differing word offsets: +0x..` | `try: <name> error <stage>`
  (exit 2) + the stage's first stderr lines (<= 5, `try:   ` prefixed). Appends one JSON line to
  .run/wave/try/<alias>_<name>.jsonl. Target bytes are never printed or written (G12).
status: drafts waves/W<k>/drafts/<alias>_<name>.c vs verdicts.jsonl rows (keyed alias,name):
  `wave: W<k> <d> drafts = <b> banked + <f> failed + <n> no-verdict`, exit 1 when unequal or a draft has no row.
  --drafts-only: every wave.json target has a draft and an attempts.jsonl row: `wave: W<k> <n> of <m> targets
  drafted`, else exit 1. --waves overrides the waves/ root. status_counts(wdir) is the importable count.
  W<k> omitted: every waves/W<k>/ dir (wave_dirs, k ascending), one `wave: W<k> ...` line each; exit 1 if any
  fails or there is no wave.
rate: per wave.json bucket, join verdicts.jsonl (banked) and attempts.jsonl ctx_k (T2/T4 rows, as status); writes and
  prints waves/W<k>/rate.txt `rate: <bucket> <bi> of <ai> insns banked, <bh> of <ah> heads, <c> k ctx per banked insn`
  (c = ctx_k of all bucket targets incl. failed / bi) + `rate: >200 unmeasured, 0 of 0 heads`. --check: docs/routing.md
  `route: <bucket> <draft|draft-twin|defer> cap <N> tries` must equal R3 per measured bucket (bi/ai >= 50% draft,
  20-50% draft-twin, < 20% defer), plus a `route: >200 ... unmeasured` line: `routing: <r> of <m> buckets routed`,
  exit 1 when r < m or a route mismatches (named).
  W<k> omitted (aggregate, R5): the same lines with every wave's per-bucket counts summed (no rate.txt written);
  --check routes against the aggregate.
port: refused (exit 1) unless `git -C refs/mmx6 rev-parse HEAD` is config/refs.toml's mmx6 `ref`. Per DIR/W<k>/wave.json
  target (DIR default waves/) with an X6 lead: port_text adapts refs/mmx6/<lead path> (map names and lead function
  must occur in it, else `error map`; whole-word rename; attribution line 1, keeps its sozud/mmx4 line; common.h ->
  types.h; mmx6/x4.h, psyq_api.h dropped and the closure of what the body references from them and mmx6/types.h
  emitted, X5 types.h names skipped, no aggregate emitted: Port maps each X6 aggregate onto an include/types.h shape
  and respells member chains (X5 path at the same offset/type, else `M2C_FIELD`); scratchpad casts -> include/addr.h
  names; register pins get `// !FAKE:`; undeclared callees get the card's X5 consensus prototype; plain char -> u8);
  each D_ data symbol not named in X5 asm/src/include is renamed from the target's HI16/LO16 address, else
  `port: <key> error symbol <name>` (no file); then try's compile/compare:
  `port: <alias>_<name> match | diff <d> of <w> words | error <stage> | no-lead`, then `port: W<k> <m> of <n> leads
  matched` (exit 0; missing wave.json exit 1). Match -> DIR/W<k>/drafts/<key>.c; else .run/wave/W<k>/port/<key>.c.
seed: per DIR/W<k>/wave.json target (or --target): asm via asm_index, else asm/<alias>/nonmatchings/**/<name>.s;
  glabel..endlabel (nonmatchings file whole) prepped for m2c -> .run/wave/W<k>/seed/<key>.s, raw m2c
  (docs/ops/decompiler.md) -> <key>.c. Never writes waves/. `seed: <key> emitted (<n> lines)` | `seed: <key> failed
  <why>` (exit 0); refs/m2c or .venv absent: `seed: m2c missing (bash tools/refs_fetch.sh m2c)`, exit 2.
--selftest: tools/wave/fixtures (synthetic, ROM-free) in .run/wave/selftest.
Stdlib only.
"""

import argparse
import contextlib
import datetime
import io
import json
import os
import re
import shutil
import struct
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FIX = Path(__file__).resolve().parent / "fixtures"
sys.path.insert(0, str(ROOT / "tools/dedup"))
sys.path.insert(0, str(ROOT / "tools/probe"))
sys.path.insert(0, str(ROOT / "tools/wave"))
import ledger  # noqa: E402  tools/wave/ledger.py: the one reader of failed/no-verdict targets

INV, GROUPS, TWINS, DRAW = (".run/census/inventory.jsonl", ".run/census/groups.jsonl", ".run/sig/twins.jsonl",
                            ".run/dedup/draw.jsonl")
LEADS = "docs/oracle/x6-leads.tsv"  # tools/sig/imgtab.py x6 --leads: an X6 function in C with this one's bytes
NEED = {"rockx5": 2, "slus": 3}
REGS = ("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra").split()


def jsonl(p):
    return [json.loads(x) for x in p.read_text().splitlines() if x.strip()]


def read_exclude(p):
    import draw  # tools/dedup/draw.py: the one parser of the restricted yaml
    return draw.read_exclude(p) if p.exists() else []


def read_leads(root):
    """{(alias, unit, vram): lead} from docs/oracle/x6-leads.tsv (tracked; absent -> no leads)."""
    p, out = root / LEADS, {}
    for ln in p.read_text().splitlines() if p.exists() else []:
        u, v, _, words, prog, xv, xname, path, pairs = ln.split("\t")
        out["slus" if u == "slus" else "rockx5", u, int(v, 16)] = {
            "prog": prog, "vram": xv, "name": xname, "path": path, "words": int(words),
            "map": [tuple(x.split("=", 1)) for x in pairs.split(";") if x]}
    return out


def unit(r):
    """The yaml code segment: rockx5 `rockx5/ovl08_800EE9BC` -> ovl08 (draw.seg_of); slus keeps its module."""
    return r["module"].split("/")[1].split("_")[0] if r["alias"] == "rockx5" else r["module"]


def asm_index(root, alias):
    """name -> .s file holding `glabel name` (segment files; nonmatchings skipped)."""
    idx = {}
    for f in sorted((root / "asm" / alias).rglob("*.s")):
        if "nonmatchings" in f.parts:
            continue
        for ln in f.read_text(errors="replace").splitlines():
            if ln.startswith("glabel "):
                idx.setdefault(ln.split()[1], f)
    return idx


def asm_body(f, name):
    """Instruction text of `name` (the part after the `/* off vram word */` comment), one line per insn."""
    out, on = [], False
    for ln in f.read_text(errors="replace").splitlines():
        t = ln.split()
        if t[:2] == ["glabel", name]:
            on = True
        elif on and t[:1] == ["endlabel"]:
            break
        elif on and t and not t[0].startswith((".", "glabel", "jlabel", "dlabel")):
            out.append(ln.split("*/", 1)[-1].strip())
    return out


def clusters(groups, twins):
    """(alias, name) -> cluster root; union-find over groups.jsonl members and twins.jsonl pairs."""
    par = {}

    def find(k):
        par.setdefault(k, k)
        while par[k] != k:
            par[k] = par[par[k]]
            k = par[k]
        return k

    for g in groups:
        ks = [(m["alias"], m["name"]) for m in g["members"]]
        for k in ks[1:]:
            par[find(k)] = find(ks[0])
    for t in twins:
        par[find((t["b"]["alias"], t["b"]["name"]))] = find((t["a"]["alias"], t["a"]["name"]))
    return find


class World:
    def __init__(self, root):
        self.root = root
        self.inv = {(r["alias"], r["name"]): r for r in jsonl(root / INV)}
        self.groups, self.twins = jsonl(root / GROUPS), jsonl(root / TWINS)
        self.draw = jsonl(root / DRAW)
        self.excl = {(e["alias"], e["vram"], e["name"]) for e in read_exclude(root / "config/dedup.exclude.yaml")}
        self.find = clusters(self.groups, self.twins)
        self.asm = {a: asm_index(root, a) for a in NEED}
        self.dr = {(r["alias"], r["name"]): r for r in self.draw}
        self.leads = read_leads(root)
        self.ledgered = ledgered(root)

    def lead(self, r):
        """The X6 lead of a draw/inventory/wave row, or None."""
        return self.leads.get((r["alias"], unit(r) if r["alias"] == "rockx5" else "slus", int(r["vram"], 16)))

    def invalid(self, t, used, per_cluster=1):
        """None or the first failing check for target row t; used = cluster roots already drawn (a set, or a Counter
        of draws per root: `cluster` once a root has per_cluster draws)."""
        k = (t["alias"], t["name"])
        if self.dr.get(k, {}).get("verdict") != "draw":
            return "not-drawable"
        if ledger.tkey(t["alias"], t["module"], t["vram"]) in self.ledgered:
            return "ledgered"
        f = self.asm[t["alias"]].get(t["name"])
        if f is None or not f.exists():
            return "no-asm"
        if self.inv.get(k, {}).get("status") != "asm":
            return "status-not-asm"
        if (t["alias"], t["vram"], t["name"]) in self.excl:
            return "excluded"
        if (used[self.find(k)] if isinstance(used, Counter) else int(self.find(k) in used)) >= per_cluster:
            return "cluster"
        return None


def ledgered(root):
    """Target keys (ledger.tkey) of the ledger's rows: tried, not banked, not c; never re-drawn."""
    return {r["key"] for r in ledger.collect(root / "waves", root / INV)[0]}


def stale_inputs(root):
    ts = subprocess.run(["git", "log", "-1", "--format=%ct", "--", "src", "config/splat.*"], cwd=ROOT,
                        capture_output=True, text=True, check=True).stdout.strip()
    ts = int(ts or 0)
    return [p for p in (INV, GROUPS, TWINS, DRAW) if not (root / p).exists() or (root / p).stat().st_mtime < ts]


def letters(bounds):
    return [chr(ord("A") + i) for i in range(len(bounds))]


def bucket_of(insns, bounds):
    """Letter of the first bound >= insns, else `>`+last bound."""
    return next((L for L, b in zip(letters(bounds), bounds) if insns <= b), f">{bounds[-1]}")


def lanes(w, bounds):
    c = Counter()
    for r in w.draw:
        if r["verdict"] == "draw":
            b = bucket_of(r["insns"], bounds)
            c[f"drawable-{b}" if b in letters(bounds) else "unmeasured"] += 1
        elif r["reason"] == "uncarveable":
            d = r.get("detail")
            c["uncarveable-" + (d if d in ("rodata", "jump-table") else "other")] += 1
        else:
            c[r["reason"]] += 1
    assert sum(c.values()) == len(w.draw), "lane partition does not cover draw.jsonl"
    return c


def draw_leverage(w, size, bounds, port=False, only=None, per_cluster=1):
    """R2: -> targets | None (refusal printed). Pool by reach desc, insns desc, (alias, vram); docs/routing.md `defer`
    buckets skipped, `draft-twin` buckets only with a banked twin, an X6 lead or a matched lever; NEED floors the whole
    wave. port (--order port-x6): the rows with an X6 lead first, and a lead is drawn whatever its bucket's route.
    only (--only): pool rows whose bucket_of is in it; short of size -> NEED floor off, the whole valid pool.
    per_cluster (--per-cluster): up to that many targets per cluster root."""
    rp = w.root / "docs/routing.md"
    route = {m[1]: m[2] for m in map(ROUTE.match, rp.read_text().splitlines()) if m} if rp.exists() else {}
    levers = read_levers(w.root)
    pool = sorted((r for r in w.draw if r["verdict"] == "draw" and r["rank"] is not None
                   and (only is None or bucket_of(r["insns"], bounds) in only)),
                  key=lambda r: (port and not w.lead(r), -r["reach"], -r["insns"], r["alias"], r["vram"]))
    got, cnt = pick(w, pool, size, bounds, port, route, levers, True, per_cluster)
    if only is not None and (len(got) < size or any(cnt[a] < n for a, n in NEED.items())):
        got, cnt = pick(w, pool, size, bounds, port, route, levers, False, per_cluster)
        if len(got) < size:
            print(f"wave: pool exhausted, drew {len(got)} of --size {size}")
        return got or None
    if len(got) < size or any(cnt[a] < n for a, n in NEED.items()):
        print(f"wave: refused -- leverage pool short: {dict(cnt)} of --size {size}, need {NEED}")
        return None
    return got


def pick(w, pool, size, bounds, port, route, levers, floor, per_cluster=1):
    """draw_leverage's selection; floor: NEED floors the wave."""
    used, got, cnt = Counter(), [], Counter()
    for r in pool:
        if len(got) == size:
            break
        b = bucket_of(r["insns"], bounds)
        how = "draft" if port and w.lead(r) else route.get(b, "draft")
        if how == "defer" or w.invalid(r, used, per_cluster):
            continue
        short = sum(max(0, n - cnt[a]) for a, n in NEED.items() if a != r["alias"])  # NEED floor, as strata
        if floor and size - len(got) - 1 < short:
            continue
        k = (r["alias"], r["name"])
        if how == "draft-twin" and not (banked_twins(w, k) or w.lead(r)
                                        or matched_levers(asm_body(w.asm[r["alias"]][r["name"]], r["name"]), levers)):
            continue
        got.append(dict({x: r[x] for x in ("alias", "module", "name", "vram", "insns")}, bucket=b, rank=r["rank"],
                        reach=r["reach"]))
        cnt[r["alias"]] += 1
        used[w.find(k)] += 1
    return got, cnt


def cmd_open(root, names, bounds, check=False):
    """Per named bucket: `open: <L> <o> open, <d> drawable, <l> ledgered[, <u> unranked]`; check: exit 1 if any o."""
    bad = stale_inputs(root)
    if bad:
        print(f"wave: refused -- stale or missing input {bad[0]} (older than last src/config/splat commit; G31)")
        return 1
    led, rows, rc = ledgered(root), [r for r in jsonl(root / DRAW) if r["verdict"] == "draw"], 0
    for L in names:
        d = [r for r in rows if bucket_of(r["insns"], bounds) == L]
        op = [r for r in d if ledger.tkey(r["alias"], r["module"], r["vram"]) not in led]
        u = sum(r["rank"] is None for r in op)
        print(f"open: {L} {len(op)} open, {len(d)} drawable, {len(d) - len(op)} ledgered"
              + (f", {u} unranked" if u else ""))
        rc |= check and bool(op)
    return int(rc)


def cmd_draw(root, wave, per, bounds, order="strata", size=None, only=None, per_cluster=1):
    bad = stale_inputs(root)
    if bad:
        print(f"wave: refused -- stale or missing input {bad[0]} (older than last src/config/splat commit; G31)")
        return 1
    out = root / "waves" / wave / "wave.json"
    if out.exists():
        print(f"wave: refused -- {out.relative_to(root)} exists")
        return 1
    w = World(root)
    if order in ("leverage", "port-x6"):
        targets = draw_leverage(w, size, bounds, order == "port-x6", only, per_cluster)
        if targets is None:
            return 1
        return write_wave(root, w, out, wave, bounds, targets, per_cluster)
    pool = sorted((r for r in w.draw if r["verdict"] == "draw" and r["rank"] is not None), key=lambda r: r["rank"])
    used, targets = set(), []
    for L, lo, hi in zip(letters(bounds), [0] + bounds, bounds):
        got, cnt = [], Counter()
        for r in pool:
            if len(got) == per:
                break
            if not lo < r["insns"] <= hi or w.invalid(r, used):
                continue
            short = sum(max(0, n - cnt[a]) for a, n in NEED.items() if a != r["alias"])
            if per - len(got) - 1 < short:
                continue
            got.append(r)
            cnt[r["alias"]] += 1
            used.add(w.find((r["alias"], r["name"])))
        if len(got) < per or any(cnt[a] < n for a, n in NEED.items()):
            print(f"wave: refused -- bucket {L} ({lo + 1}-{hi} insns) short: {dict(cnt)} of --per {per}, need {NEED}")
            return 1
        targets += [dict({k: r[k] for k in ("alias", "module", "name", "vram", "insns")}, bucket=L, rank=r["rank"],
                         reach=r["reach"]) for r in got]
    return write_wave(root, w, out, wave, bounds, targets)


def write_wave(root, w, out, wave, bounds, targets, per_cluster=1):
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"wave": wave, "date": datetime.date.today().isoformat(), "buckets": bounds,
                               "targets": targets}, indent=1) + "\n")
    n_bad, used = 0, Counter()
    for t in json.loads(out.read_text())["targets"]:
        why = w.invalid(t, used, per_cluster)
        used[w.find((t["alias"], t["name"]))] += 1
        if why:
            n_bad += 1
            print(f"wave: invalid {t['alias']}_{t['name']} {why}")
    print(f"wave: {wave} drew {len(targets)} targets, {n_bad} invalid")
    for k, v in sorted(lanes(w, bounds).items()):
        print(f"lane: {k} {v}")
    return 1 if n_bad else 0


def norm_insn(s):
    """splat insn text -> gcc -S style (`addu $2,$4,$0`) so levers.yaml tells can match."""
    s = re.sub(r"\$(" + "|".join(REGS) + r")\b", lambda m: f"${REGS.index(m.group(1))}", s)
    op, _, rest = s.partition(" ")
    return f"\t{op}\t" + re.sub(r"\s*,\s*", ",", rest.strip())


def src_lines(root):
    out = []
    for f in sorted(list((root / "src").rglob("*.c")) + list((root / "include").rglob("*.h"))):
        for i, ln in enumerate(f.read_text(errors="replace").splitlines(), 1):
            out.append((f.relative_to(root), i, ln))
    return out


def read_levers(root):
    lv = root / "docs/codegen-map/levers.yaml"
    return {x["id"]: x.get("tell") for x in json.loads(lv.read_text())} if lv.exists() else {}  # JSON is YAML


def banked_twins(w, k):
    """Sorted cluster partners of k with inventory status c (the card's banked twins)."""
    me = w.find(k)
    return sorted({p for p in set(w.inv) | {(m["alias"], m["name"]) for g in w.groups for m in g["members"]}
                   if p != k and w.find(p) == me and w.inv.get(p, {}).get("status") == "c"})


def matched_levers(body, levers):
    """Lever ids whose levers.yaml tell matches the norm_insn body."""
    norm = "\n".join(norm_insn(x) for x in body)
    return [lid for lid, tell in levers.items() if tell and re.search(tell, norm, re.M)]


def twin_x6(lead):
    """The card's `## Twin in X6` lines: the X6 C that has this target's bytes, and the names to change."""
    if not lead:
        return ["none"]
    return [f"X6 {lead['prog']} {lead['name']} ({lead['vram']}) has this target's bytes under the relocation mask "
            f"({LEADS}). Its C: `refs/mmx6/{lead['path']}` (`bash tools/refs_fetch.sh mmx6`; AGPL-3.0, THIRD_PARTY.md).",
            "- Seed the draft from that function's C, then rename by this map (X6 name -> X5 name):"] + \
        [f"  - `{a}` -> `{b}`" for a, b in lead["map"]] + [
            "- Keep X5's own types and declarations (include/, the sections below), not X6's headers. Start the draft"
            " with `/* Adapted from mmx6 @<pin> <path> ... */`, and keep the X6 file's own `Adapted from` line (sozud/mmx4).",
            "- X6's cc1 has `-funsigned-char`; X5's has not (its `-D__CHAR_UNSIGNED__` is cpp only), so X5 compiles a"
            " plain `char` signed: spell each plain `char` of the X6 C as `u8`, or `s8` where the target sign-extends.",
            "- An X6 type X5 lacks (`mmx6/x4.h`, `mmx6/psyq_api.h`): declare only the fields the body touches, at their"
            " offsets, and a prototype for every callee the X6 file left undeclared.",
            "- A name the map lacks keeps its X5 spelling from the target's asm. The lead is not a match: `try` and the "
            "gate prove the draft."]


def callee_consensus(c, lines):
    """The card's `## Callee decl consensus` for callee c: Counter of normalised decls over src/include lines."""
    pat = re.compile(rf"^(?:extern\s+)?[A-Za-z_][\w\s*]*\b{c}\s*\([^;{{]*\)\s*[;{{]?\s*$")
    return Counter(" ".join(ln.replace("extern ", "", 1).rstrip("{; ").split()) + ";"
                   for _, _, ln in lines if pat.match(ln))


def card_text(w, t, lines, levers, cook):
    root, alias, name = w.root, t["alias"], t["name"]
    body = asm_body(w.asm[alias][name], name)
    text = "\n".join(body)
    callees = list(dict.fromkeys(re.findall(r"\bjal\s+([A-Za-z_]\w*)", text)))
    globs = list(dict.fromkeys(re.findall(r"%(?:hi|lo|gp_rel)\(([A-Za-z_]\w*)", text)))
    partners = banked_twins(w, (alias, name))
    out = [f"# {alias}_{name}", "", "Laws: tools/wave/LAWS.md. Try: `waves.py try <draft.c> --target "
           f"{alias}_{name}`.", "", "## Target",
           f"alias {alias} · module {t['module']} · name {name} · vram {t['vram']} · insns {t['insns']} · "
           f"bucket {t['bucket']}", "", "## Dest file", f"src/{alias}/{name}.c", "", "## Banked twins"]
    for a, n in partners:
        hit = [p for p in [root / f"src/{a}/{n}.c"] if p.exists()] + sorted((root / "src").rglob(f"{n}.c"))
        out.append(f"- {a} {n}: {hit[0].relative_to(root) if hit else '(status c, no src file found)'}")
    out += [] if partners else ["none"]
    out += ["", "## Twin in X6"] + twin_x6(w.lead(t))
    out += ["", "## Dest declarations"]
    syms = root / f"config/symbols.{alias}.txt"
    symtxt = syms.read_text().splitlines() if syms.exists() else []
    for s in callees + globs:
        hits = [f"{syms.relative_to(root)}: `{ln.strip()}`" for ln in symtxt if re.match(rf"\s*{s}\s*=", ln)]
        hits += [f"{f}:{i}: `{ln.strip()}`" for f, i, ln in lines if ln.startswith("extern") and re.search(rf"\b{s}\b", ln)]
        out.append(f"- {s}: " + ("; ".join(hits) if hits else "none"))
    out += [] if callees + globs else ["none (no symbol references)"]
    out += ["", "## Callee decl consensus"]
    for c in callees:
        cnt = callee_consensus(c, lines)
        out.append(f"- {c}: " + ("; ".join(f"{v}x `{d}`" for d, v in cnt.most_common()) if cnt else "none found"))
    out += [] if callees else ["none (no jal)"]
    led = root / "docs/ledger.md"
    past = [ln.strip() for ln in led.read_text().splitlines() if re.search(rf"\b{name}\b", ln)] if led.exists() else []
    out += ["", "## Past attempts"] + ([f"- {p}" for p in past] or ["none"])
    ids = matched_levers(body, levers)
    ids += [m for p in past for m in re.findall(r"\blever:([\w-]+)", p)]
    ids = list(dict.fromkeys(ids))
    out += ["", "## Levers"] + ([f"- {i}" for i in ids] or ["none matched"]) + [
        "Symptom index: docs/codegen-map/SYMPTOMS.md", "", "## Same-unit neighbours"]
    nb = sorted(r["name"] for r in w.inv.values() if r["alias"] == alias and r["status"] == "c"
                and r["name"] != name and unit(r) == unit(t))
    hits = [f"- {f}:{i}: `{ln.strip()}`" for f, i, ln in lines if f.stem in nb and f.parts[1] == alias
            and ln[:1] not in ("", " ", "\t", "#", "/", "}", "{") and any(re.search(rf"\b{g}\b", ln) for g in globs)]
    out += hits or [f"none ({len(nb)} neighbours in unit {unit(t)}, no shared globals)"]
    md = "\n".join(out) + "\n"
    unres = [i for i in ids if i not in levers and i not in cook]
    unres += [c for c in dict.fromkeys(re.findall(r"\bC\d{4}\b", md)) if c not in cook]
    return md, unres


def cmd_card(root, wave):
    wj = root / "waves" / wave / "wave.json"
    if not wj.exists():
        print(f"card: refused -- {wj.relative_to(root)} missing")
        return 1
    w = World(root)
    levers = read_levers(root)
    ci =root / "cookbook/INDEX.md"
    cook = set(re.findall(r"^(C\d{4}) \|", ci.read_text(), re.M)) if ci.exists() else set()
    lines, bad, n = src_lines(root), 0, 0
    for t in json.loads(wj.read_text())["targets"]:
        md, unres = card_text(w, t, lines, levers, cook)
        key = f"{t['alias']}_{t['name']}"
        if unres:
            bad += 1
            print(f"card: refused {key} -- unresolved {' '.join(unres)} (G44)")
            continue
        d = root / ".run/wave" / wave / "packs" / key
        d.mkdir(parents=True, exist_ok=True)
        (d / "card.md").write_text(md)
        (d / "target.s").unlink(missing_ok=True)
        (d / "target.s").symlink_to(w.asm[t["alias"]][t["name"]].resolve())
        n += 1
    print(f"card: {wave} {n} packs, {bad} refused")
    return 1 if bad else 0


def compile_func(draft, tag, name):
    """try's compile path: draft -> probe.compile_obj (reconcile.triple(), scratch .run/probe/<tag>/) -> read_func.
    -> (text bytes, masks, None) | (None, None, stage)."""
    import probe
    import reconcile
    obj, stage = probe.compile_obj(Path(draft).resolve(), tag, reconcile.triple())
    if obj is None:
        return None, None, stage
    try:
        ours, masks = probe.read_func(obj, name)
    except KeyError:
        return None, None, "symbol"
    return ours, masks, None


def try_draft(draft, row):
    """cmd_try's compile + masked compare of draft against inventory/wave row's target -> (res, d, detail lines)."""
    import probe
    alias, name = row["alias"], row["name"]
    tag = f"wave/{alias}_{name}"
    scratch = ROOT / ".run/probe" / tag
    assert f"{alias}_{name}" == scratch.name, scratch  # per-target scratch: drafts never share a dir
    ours, masks, stage = compile_func(draft, tag, name)
    w, detail = row["insns"], []
    if ours is None:
        res, d = f"error {stage}", None
        import reconcile
        err = scratch / reconcile.triple()["id"] / f"{stage}.err"  # probe.compile_obj's stderr (our draft, no bytes)
        detail = (err.read_text(errors="replace").splitlines() if err.exists() else [])[:5]
    else:
        tb = probe.target_bytes({"alias": alias, "module": unit(row), "vram": int(row["vram"], 16), "size": 4 * w})
        d = probe.diff_words(ours, tb, masks)
        res = "match" if d == 0 else f"diff {d} of {w} words"
        a, b = probe.masked(ours, masks), probe.masked(tb, masks)
        offs = [f"+0x{4 * i:X}" for i in range(max(len(a), len(b))) if i >= min(len(a), len(b)) or a[i] != b[i]]
        detail = [f"differing word offsets: {' '.join(offs[:16])}" + (" ..." if len(offs) > 16 else "")] if d else []
    return res, d, detail


def cmd_try(draft, target):
    alias, _, name = target.partition("_")
    row = {(r["alias"], r["name"]): r for r in jsonl(ROOT / INV)}.get((alias, name))
    if row is None:
        print(f"try: refused -- {target} not in {INV}")
        return 2
    res, d, detail = try_draft(draft, row)
    w = row["insns"]
    log = ROOT / ".run/wave/try" / f"{alias}_{name}.jsonl"
    log.parent.mkdir(parents=True, exist_ok=True)
    with log.open("a") as f:
        f.write(json.dumps({"draft": str(draft), "result": res.split()[0], "d": d, "w": w}) + "\n")
    print(f"try: {name} {res}")
    for ln in detail:
        print(f"try:   {ln}")
    return 0 if res == "match" else 1 if res.startswith("diff") else 2


X6_HDRS = ("include/mmx6/types.h", "include/mmx6/psyq_api.h", "include/mmx6/x4.h")  # closure sources, include order
X6_DROP = ("mmx6/x4.h", "mmx6/psyq_api.h")
CKW = set("auto break case char const continue default do double else enum extern float for goto if int long register "
          "return short signed sizeof static struct switch typedef union unsigned void volatile while asm".split())
BASE = {"char": (1, 1), "short": (2, 2), "int": (4, 4), "long": (4, 4), "float": (4, 4), "double": (8, 8),
        "long long": (8, 8), "void": (1, 1)}  # o32; spec words signed/unsigned/const/volatile dropped first


def x6_pin(root):
    """config/refs.toml mmx6 `ref` (the pin) and refs/mmx6's HEAD; port refuses when they differ."""
    import tomllib
    pin = next(r["ref"] for r in tomllib.loads((root / "config/refs.toml").read_text())["ref"] if r["name"] == "mmx6")
    head = subprocess.run(["git", "-C", str(root / "refs/mmx6"), "rev-parse", "HEAD"], capture_output=True, text=True)
    return pin, head.stdout.strip()


def uncomment(s):
    return re.sub(r"//[^\n]*", "", re.sub(r"/\*.*?\*/", " ", s, flags=re.S))


def c_entities(text):
    """Top-level entities of a header: [{names, text, kind}] (kind macro|decl); #if/#ifndef/#endif/#include dropped."""
    out, buf, depth, lines = [], [], 0, uncomment(text).splitlines()
    i = 0
    while i < len(lines):
        ln = lines[i]
        i += 1
        if not buf and ln.lstrip().startswith("#"):
            while ln.endswith("\\") and i < len(lines):
                ln, i = ln + "\n" + lines[i], i + 1
            m = re.match(r"\s*#\s*define\s+(\w+)", ln)
            if m:
                out.append({"names": {m[1]}, "text": ln.strip(), "kind": "macro"})
            continue
        if buf or ln.strip():
            buf.append(ln)
            depth += ln.count("{") - ln.count("}")
        if buf and depth == 0 and ln.rstrip().endswith(";"):
            d = "\n".join(buf).strip()
            buf = []
            names = {f"{k} {t}" for k, t in re.findall(r"^(?:typedef\s+)?(struct|union|enum)\s+(\w+)\s*\{", d)}
            if re.match(r"(?:typedef\s+)?enum\b[^{]*\{", d):
                names |= set(re.findall(r"(\w+)\s*(?:=[^,}]*)?[,}]", d[d.index("{"):]))
            if d.startswith("typedef"):
                m = re.search(r"\(\s*\*\s*(\w+)\s*\)\s*\(", d) or re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*;$", d)
                names.add(m[1])
            elif "{" not in d:
                m = re.search(r"(\w+)\s*\(", d) or re.search(r"(\w+)\s*(?:\[[^\]]*\]\s*)*;$", d)
                names.add(m[1])
            out.append({"names": names, "text": d, "kind": "decl"})
    return out


def c_refs(text):
    """Keys a text references: `struct T`/`union T`/`enum T` tags and plain identifiers (C keywords dropped)."""
    t = uncomment(text)
    return {f"{k} {n}" for k, n in re.findall(r"\b(struct|union|enum)\s+(\w+)", t)} | \
        (set(re.findall(r"\b[A-Za-z_]\w*\b", t)) - CKW)


def brace_split(s, sep):
    """Split s at sep characters outside (), [], {}."""
    out, cur, depth = [], "", 0
    for ch in s:
        depth += (ch in "([{") - (ch in ")]}")
        if ch == sep and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    return out + [cur]


class Layout:
    """o32 sizes of the X6 header types (typedefs, tags), for struct trimming. KeyError/ValueError: not computable."""

    def __init__(self, ents):
        self.tag, self.tdef = {}, {}
        for e in ents:
            for n in e["names"]:
                if " " in n:
                    self.tag[n] = e["text"]
                elif e["text"].startswith("typedef"):
                    self.tdef[n] = e["text"][len("typedef"):].rstrip(";")

    @staticmethod
    def dim(expr):
        if not re.fullmatch(r"[\s0-9a-fA-FxX+\-*/()]*", expr) or \
                re.search(r"[a-fA-FxX]", re.sub(r"0[xX][0-9a-fA-F]+", "0", expr)):  # literals and + - * / ( ) only
            raise ValueError(expr)
        return eval(expr.replace("/", "//"), {"__builtins__": {}})

    def decl(self, d):
        """'spec declarators' -> (spec text, [(name, declarator text, size, align)]); an unnamed full-width bitfield
        (`s8 : 8;`) is padding, name ''; other bitfields raise ValueError. Sizes are computed only when needed."""
        d = d.strip()
        m = re.match(r"(?:struct|union)\s*\w*\s*\{", d)
        if m:
            depth, j = 0, 0
            for j, ch in enumerate(d):
                depth += (ch == "{") - (ch == "}")
                if ch == "}" and depth == 0:
                    break
            spec, rest = d[:j + 1], d[j + 1:]
            sz = lambda: self.agg(spec)  # noqa: E731
        else:
            words, pos = [], 0
            for m in re.finditer(r"\s*(\w+)", d):
                if m.start() != pos:
                    break
                w = m[1]
                if w in ("struct", "union", "enum"):
                    words.append(w)
                elif words and words[-1] in ("struct", "union", "enum"):
                    words[-1] += " " + w
                elif w in BASE or w in ("signed", "unsigned", "const", "volatile") or \
                        all(x in ("const", "volatile") for x in words):
                    words.append(w)
                else:
                    break
                pos = m.end()
            spec, rest = d[:pos], d[pos:]
            sz = lambda: self.spec(words)  # noqa: E731
        out = []
        for dc in brace_split(rest, ","):
            dc = re.sub(r"\b(?:const|volatile)\b", "", dc)
            if ":" in dc:
                w = re.fullmatch(r"\s*:\s*(\d+)\s*", dc)
                if not w or int(w[1]) != 8 * sz()[0]:
                    raise ValueError("bitfield")
                out.append(("", dc.strip(), *sz()))
                continue
            m = re.fullmatch(r"\s*\(\s*\*+\s*(\w+)\s*((?:\[[^\]]*\]\s*)*)\)\s*\(.*\)\s*", dc, re.S) or \
                re.fullmatch(r"\s*(?:\*\s*)*(\w+)\s*((?:\[[^\]]*\]\s*)*)", dc)
            if not m:
                raise ValueError(dc)
            n = 1
            for x in re.findall(r"\[([^\]]*)\]", m[2]):
                n *= self.dim(x)
            s, a = (4, 4) if "*" in dc else sz()
            out.append((m[1], dc.strip(), s * n, a))
        return spec.strip(), out

    def spec(self, words):
        ws = [w for w in words if w not in ("signed", "unsigned", "const", "volatile")] or ["int"]
        k = " ".join(ws)
        if k in BASE or k in ("short int", "long int"):
            return BASE.get(k) or BASE[ws[0]]
        if ws[0].startswith("enum "):
            return 4, 4
        if ws[0].startswith(("struct ", "union ")):
            return self.agg(self.tag[ws[0]])
        _, ds = self.decl(self.tdef[ws[0]])
        return ds[0][2], ds[0][3]

    def agg(self, text):
        """(size, align) of a struct/union definition text."""
        return self.fields(text)[1:]

    def fields(self, text):
        """-> ([(name, decl text, off, size)], size, align) of a struct/union definition text."""
        uni = re.match(r"(?:typedef\s+)?union\b", text) is not None
        body = text[text.index("{") + 1:text.rindex("}")]
        out, off, al = [], 0, 1
        for d in brace_split(body, ";"):
            if not d.strip():
                continue
            spec, ds = self.decl(d)
            for n, dc, s, a in ds:
                o = 0 if uni else -(-off // a) * a
                out.append((n, f"{spec} {dc};", o, s))
                off = max(off, s) if uni else o + s
                al = max(al, a)
        return out, -(-off // al) * al, al


INTS = {"char": "u8", "signed char": "s8", "unsigned char": "u8", "short": "s16", "short int": "s16",
        "signed short": "s16", "signed short int": "s16", "unsigned short": "u16", "unsigned short int": "u16",
        "int": "s32", "signed": "s32", "signed int": "s32", "long": "s32", "long int": "s32", "signed long": "s32",
        "unsigned": "u32", "unsigned int": "u32", "unsigned long": "u32", "unsigned long int": "u32",
        "float": "f32", "void": "void"}  # canon of base type words (char is unsigned: -D__CHAR_UNSIGNED__)
INT_SIZE = {"u8": 1, "s8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "void": 1}
TOK = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|->|\w+|\S', re.S)
M2C_DEF = "#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))"
DSYM = re.compile(r"\bD_[0-9A-Fa-f]{8}\w*")
CERR = (KeyError, ValueError, IndexError, StopIteration, RecursionError, TypeError)


class CTypes(Layout):
    """Layout plus member types, for port's type mapping. A type: ("int", canon) | ("ptr", t) | ("arr", t, n) |
    ("agg", key) | ("fn",) | ("opaque", spelling); key = (struct|union, "{body}"); names[key]: spellings, typedefs first."""

    def __init__(self, ents):
        super().__init__(ents)
        self.names, self.memo = {}, {}
        for e in ents:
            for n in sorted(e["names"], key=lambda n: (" " in n, n)):
                t = self.named(n)
                if t and t[0] == "agg":
                    self.names.setdefault(t[1], []).append(n)

    def named(self, n):
        """Type of a spelling (`struct T`, `union T`, a typedef name) or None."""
        try:
            if " " in n:
                return self.of_spec(self.tag[n]) if n in self.tag else ("opaque", n)
            spec, ds = self.decl(self.tdef[n])
            return self.apply(self.of_spec(spec), ds[0][1])
        except CERR:
            return None

    def of_spec(self, spec):
        m = re.search(r"\b(struct|union)\s*\w*\s*\{", spec)
        if m:
            return "agg", (m[1], spec[spec.index("{", m.start()):spec.rindex("}") + 1])
        ws = [w for w in re.findall(r"\w+", spec) if w not in ("const", "volatile", "typedef")]
        if ws[:1] in (["struct"], ["union"]):
            n = " ".join(ws[:2])
            return self.of_spec(self.tag[n]) if n in self.tag else ("opaque", n)
        if ws[:1] == ["enum"]:
            return "int", "s32"
        k = " ".join(ws) or "int"
        if k in INTS:
            return "int", INTS[k]
        t = self.named(ws[0])
        if t is None:
            raise KeyError(ws[0])
        return t

    @staticmethod
    def apply(t, dc):
        """Type t through declarator dc: `*`s, then `[n]`s outermost; `(*f)(...)` -> pointer to function."""
        dc = re.sub(r"\b(?:const|volatile)\b", "", dc)
        if re.match(r"\s*\(\s*\*", dc):
            return "ptr", ("fn",)
        for _ in range(dc.split("[")[0].count("*")):
            t = "ptr", t
        for x in reversed(re.findall(r"\[([^\]]*)\]", dc)):
            t = "arr", t, (Layout.dim(x) if x.strip() else 0)
        return t

    def members(self, key):
        """[(name, off, type)] of an aggregate, padding dropped; None when not computable."""
        if key not in self.memo:
            try:
                out = []
                for n, d, off, _ in self.fields(f"{key[0]} {key[1]}")[0]:
                    if n:
                        spec, ds = self.decl(d.rstrip(";"))
                        out.append((n, off, self.apply(self.of_spec(spec), ds[0][1])))
                self.memo[key] = out
            except CERR:
                self.memo[key] = None
        return self.memo[key]

    def size(self, t):
        """Byte size of type t or None."""
        try:
            if t[0] == "int":
                return INT_SIZE[t[1]]
            if t[0] == "ptr":
                return 4
            if t[0] == "arr":
                return t[2] * self.size(t[1])
            return self.agg(f"{t[1][0]} {t[1][1]}")[0] if t[0] == "agg" else None
        except CERR:
            return None

    def walk(self, t, steps):
        """Follow steps (".", name) / ("[", int | token range) from aggregate t -> (frames, off, leaf, n) or None.
        n steps consumed (stops at a non-array index); frames [(off, elem, idx)] per non-constant array index; off is
        the leaf's offset in the last frame."""
        frames, off, n = [], 0, 0
        for kind, v in steps:
            if kind == ".":
                hit = next((m for m in (self.members(t[1]) if t[0] == "agg" else None) or () if m[0] == v), None)
                if hit is None:
                    return None
                off, t = off + hit[1], hit[2]
            elif t[0] != "arr" or self.size(t[1]) is None:
                break
            elif isinstance(v, int):
                off, t = off + v * self.size(t[1]), t[1]
            else:
                frames.append((off, t[1], v))
                off, t = 0, t[1]
            n += 1
        return frames, off, t, n

    def sub(self, t, off):
        """(path, type) of every subobject of t at byte offset off, outermost first; `pad*` members skipped."""
        if off == 0:
            yield [], t
        if t[0] == "agg":
            for n, o, mt in self.members(t[1]) or ():
                s = self.size(mt)
                if s and not n.startswith("pad") and o <= off < o + s:
                    for p, tt in self.sub(mt, off - o):
                        yield [(".", n)] + p, tt
        elif t[0] == "arr" and self.size(t[1]):
            k = off // self.size(t[1])
            for p, tt in self.sub(t[1], off - k * self.size(t[1])):
                yield [("[", k)] + p, tt


class Port:
    """X6 code onto the X5 type layer: each X6 aggregate maps to an include/types.h shape (same name; else the shape
    resolving most of its member accesses, then most same-name same-offset fields; pointer members carry the map
    on), else `void`. A member chain keeps its X6 spelling when it resolves the same in X5, else takes the X5 path at
    the same offset and type, else `M2C_FIELD(base, T*, off)`."""

    def __init__(self, l6, l5, text):
        self.l6, self.l5, self.src, self.map, self.segs, self.collect, self.used = l6, l5, text, {}, {}, True, False
        self.toks = [(m.start(), m.end(), m[0]) for m in TOK.finditer(text) if not m[0].startswith(("/*", "//"))]
        self.match, st = {}, []
        for i, (_, _, s) in enumerate(self.toks):
            if s in ("(", "["):
                st.append(i)
            elif s in (")", "]") and st:
                j = st.pop()
                self.match[j], self.match[i] = i, j
        self.macros = {m[1]: t for m in re.finditer(r"^[ \t]*#[ \t]*define[ \t]+(\w+)(?:\([^)]*\))?[ \t]*(.*)$",
                                                    text, re.M) if (t := self.ctype(m[2].strip()))}
        self.vars = {}
        self.decls()

    def tk(self, i):
        return self.toks[i][2] if 0 <= i < len(self.toks) else ""

    def gap(self, i):  # source text between token i-1 and token i
        return self.src[self.toks[i - 1][1]:self.toks[i][0]]

    def agg6(self, s, i):  # X6 aggregate type spelled by token i (`struct T` from i-1 or a typedef name), or None
        if self.tk(i - 1) in (".", "->", "struct", "union") or not re.match(r"[A-Za-z_]", s) or s in CKW:
            return None
        t = self.l6.named(s)
        return t if t and t[0] == "agg" else None

    def ctype(self, s):
        """X6 type of a cast expression text `(*(T*)x)` / `((T*)x)`, or None."""
        m = re.match(r"\(\s*(\*?)\s*\(\s*((?:const\s+)?(?:(?:struct|union)\s+)?\w+)\s*((?:\*\s*)*)\)", s)
        if not m:
            return None
        w = re.sub(r"^const\s+", "", m[2])
        t = ("int", INTS[w]) if w in INTS else self.l6.named(w)
        if t is None:
            return None
        t = self.l6.apply(t, m[3])
        return self.deref(t) if m[1] else t

    @staticmethod
    def deref(t):
        return t[1] if t and t[0] in ("ptr", "arr") else None

    def decls(self):
        """vars: X6 type of every declarator whose type is an X6 aggregate (params, locals, externs)."""
        for i, (_, _, s) in enumerate(self.toks):
            if s in ("struct", "union") and re.match(r"[A-Za-z_]", self.tk(i + 1)):
                base, j = self.l6.named(f"{s} {self.tk(i + 1)}"), i + 2
            else:
                base, j = self.agg6(s, i), i + 1
            while base:
                t = base
                while self.tk(j) == "*":
                    t, j = ("ptr", t), j + 1
                name = self.tk(j)
                if not re.match(r"[A-Za-z_]\w*$", name) or name in CKW:
                    break
                j, dims = j + 1, []
                while self.tk(j) == "[" and j in self.match:
                    dims.append(self.src[self.toks[j][1]:self.toks[self.match[j]][0]])
                    j = self.match[j] + 1
                try:
                    for x in reversed(dims):
                        t = "arr", t, (Layout.dim(x) if x.strip() else 0)
                except ValueError:
                    t = "arr", t, 0
                if self.tk(j) not in (",", ";", ")", "="):
                    break
                self.vars[name] = t
                if self.tk(j) != ",":
                    break
                j += 1

    def to5(self, t):
        """The X5 type of X6 type t under the map (an unmapped aggregate -> None, behind a pointer -> void)."""
        if t is None or t[0] in ("fn", "opaque"):
            return t if t and t[0] == "fn" else None
        if t[0] == "agg":
            return ("agg", self.map[t[1]]) if self.map.get(t[1]) else None
        if t[0] == "int":
            return t
        inner = self.to5(t[1])
        if t[0] == "ptr":
            return "ptr", inner or ("int", "void")
        return ("arr", inner, t[2]) if inner else None

    def spell5(self, t):
        if t[0] == "int":
            return t[1]
        if t[0] == "agg":
            return self.l5.names[t[1]][0]
        if t[0] == "ptr":
            s = "void" if t[1][0] == "fn" else self.spell5(t[1])
            return s and s + "*"
        return None

    def compat(self, a, b):
        """X5 type b reads what X6 type a reads (same widths, signedness, pointee shapes under the map)."""
        if a is None or b is None or a[0] != b[0]:
            return False
        if a[0] == "int":
            return a[1] == b[1]
        if a[0] == "agg":
            return self.map.get(a[1], b[1]) == b[1] and self.l6.size(a) == self.l5.size(b)
        if a[0] == "arr":
            return a[2] == b[2] and self.compat(a[1], b[1])
        if a[0] == "ptr":
            x, y = a[1], b[1]
            if x[0] == "agg" and y[0] == "agg":
                return self.map.get(x[1], y[1]) == y[1]
            return (x[0] == y[0] == "int" and "void" in (x[1], y[1])) or self.compat(x, y)
        return True

    def find5(self, t, frames, off, leaf, top=True):
        """X5 path in t to the subobject the X6 frames/off/leaf name, as (path, X5 type), or None."""
        if not frames:
            return next(((p, tt) for p, tt in self.l5.sub(t, off) if (p or not top) and self.compat(leaf, tt)), None)
        aoff, e6, idx = frames[0]
        for p, tt in self.l5.sub(t, aoff):
            if tt[0] == "arr" and self.l5.size(tt[1]) == self.l6.size(e6):
                r = self.find5(tt[1], frames[1:], off, leaf, False)
                if r:
                    return p + [("[", idx)] + r[0], r[1]
        return None

    def chain(self, k, j, ops, t6):
        """Rewritten text of the chain: primary tokens k..j-1 (X6 type t6) then postfix ops [(op, token index)]."""
        acc = self.tk(k) + (self.gap(k + 1) + self.emit(k + 1, j) if j > k + 1 else "")
        t5, i = (None if self.collect else self.to5(t6)), 0
        while i < len(ops):
            op, x = ops[i]
            if op == "[":
                acc += self.gap(x) + self.emit(x, self.match[x] + 1)
                t6, t5, i = self.deref(t6), self.deref(t5), i + 1
                continue
            obj6 = self.deref(t6) if op == "->" else t6
            steps = [(".", self.tk(x + 1))]
            for o, y in ops[i + 1:]:
                if o == "->":
                    break
                if o == ".":
                    steps.append((".", self.tk(y + 1)))
                else:
                    c = self.tk(y + 1) if self.match[y] == y + 2 else ""
                    steps.append(("[", int(c, 16 if c[:2].lower() == "0x" else 10)
                                  if re.fullmatch(r"0[xX][0-9a-fA-F]+|[1-9]\d*|0", c) else (y + 1, self.match[y])))
            r6 = self.l6.walk(obj6, steps) if obj6 and obj6[0] == "agg" else None
            if not r6:
                return acc + self.gap(x) + self.emit(x, self.end(ops[-1]))
            frames, off, leaf6, n = r6
            if self.collect:
                self.segs.setdefault(obj6[1], []).append((frames, off, leaf6))
            orig = self.gap(x) + self.emit(x, self.end(ops[i + n - 1]))
            obj5 = (self.deref(t5) if op == "->" else t5) if not self.collect else None
            text, leaf5 = orig, None
            if obj5 and obj5[0] == "agg":
                r5 = self.l5.walk(obj5, steps[:n])
                if r5 and r5[3] == n and r5[1] == off and self.compat(leaf6, r5[2]) and \
                        [(a, self.l6.size(e)) for a, e, _ in frames] == [(a, self.l5.size(e)) for a, e, _ in r5[0]]:
                    leaf5 = r5[2]
                else:
                    f = self.find5(obj5, frames, off, leaf6)
                    if f:
                        leaf5, text = f[1], self.gap(x) + op + "".join(
                            ("." if q else "") + v if kind == "." else "[" + (
                                str(v) if isinstance(v, int) else self.emit(*v)) + "]"
                            for q, (kind, v) in enumerate(f[0]))
            if leaf5 is None and not frames and not self.collect:
                leaf5 = self.to5(leaf6)
                sp = leaf5 and self.spell5(leaf5)
                if sp:
                    base = acc if op == "->" else "&" + acc
                    acc, text, self.used = f"M2C_FIELD({base}, {sp}*, 0x{off:X})", "", True
            for a, b in ((leaf6, leaf5), (self.deref(leaf6), self.deref(leaf5))):
                if not self.collect and a and b and a[0] == b[0] == "agg":
                    self.map.setdefault(a[1], b[1])
            acc += text
            t6, t5, i = leaf6, leaf5, i + n
        return acc

    def end(self, op):  # token index after a postfix op
        return self.match[op[1]] + 1 if op[0] == "[" else op[1] + 2

    def post(self, j, hi):
        ops = []
        while j < hi:
            s = self.tk(j)
            if s == "[" and j in self.match:
                ops.append(("[", j))
                j = self.match[j] + 1
            elif s in (".", "->") and j + 1 < hi and re.match(r"[A-Za-z_]", self.tk(j + 1)):
                ops.append((s, j))
                j += 2
            else:
                break
        return j, ops

    def primary(self, k):
        """(end token, X6 type | None) of a chain primary at token k (identifier, call, parenthesis), or (None, None)."""
        s = self.tk(k)
        if self.tk(k - 1) in (".", "->"):
            return None, None
        if re.match(r"[A-Za-z_]", s) and s not in CKW:
            if self.tk(k + 1) == "(" and k + 1 in self.match:
                return self.match[k + 1] + 1, self.macros.get(s)
            return k + 1, self.macros.get(s) or self.vars.get(s)
        if s == "(" and k in self.match:
            return self.match[k] + 1, self.ctype(self.src[self.toks[k][0]:self.toks[self.match[k]][1]])
        return None, None

    def emit(self, lo, hi):
        """Text of tokens lo..hi-1 with every member chain rewritten."""
        out, k = [], lo
        while k < hi:
            if k > lo:
                out.append(self.gap(k))
            j, t = self.primary(k)
            if j and j <= hi:
                e, ops = self.post(j, hi)
                if any(o != "[" for o, _ in ops):
                    out.append(self.chain(k, j, ops, t))
                    k = e
                    continue
            out.append(self.tk(k))
            k += 1
        return "".join(out)

    def run(self):
        """The rewritten text: collect accesses, map the X6 aggregates, emit, respell the X6 type names."""
        if not self.toks:
            return self.src
        self.emit(0, len(self.toks))
        keys = list(dict.fromkeys([t[1] for i, (_, _, s) in enumerate(self.toks)
                                   for t in [self.agg6(s, i) or (self.l6.named(f"{self.tk(i - 1)} {s}")
                                                                 if self.tk(i - 1) in ("struct", "union") else None)]
                                   if t and t[0] == "agg"] + list(self.segs)))
        cands = [c for c in self.l5.names if self.l5.members(c)]
        same = lambda k: next((t[1] for n in self.l6.names.get(k, []) if (t := self.l5.named(n)) and  # noqa: E731
                               t[0] == "agg"), None)
        for k6 in sorted(keys, key=lambda k: (same(k) is None, -len(self.segs.get(k, ())))):
            if k6 in self.map:
                continue
            c = same(k6)
            if c is None:
                f6 = {(n, o) for n, o, _ in self.l6.members(k6) or () if not n.startswith("pad")}
                sc = max(((sum(self.find5(("agg", c), *s) is not None for s in self.segs.get(k6, ())),
                           len(f6 & {(n, o) for n, o, _ in self.l5.members(c)}),
                           -abs((self.l6.size(("agg", k6)) or 0) - (self.l5.size(("agg", c)) or 0)), -q, c)
                          for q, c in enumerate(cands)), default=None)
                c = sc[-1] if sc and (sc[0] or sc[1]) else None
            self.map[k6] = c
            m5 = {(n, o): t for n, o, t in self.l5.members(c) or ()} if c else {}
            for n, o, t in self.l6.members(k6) or ():
                u = m5.get((n, o))
                while u and t[0] == u[0] and t[0] in ("ptr", "arr"):
                    t, u = t[1], u[1]
                if u and t[0] == u[0] == "agg":
                    self.map.setdefault(t[1], u[1])
        self.collect = False
        text = self.src[:self.toks[0][0]] + self.emit(0, len(self.toks)) + self.src[self.toks[-1][1]:]

        def respell(m):
            s = m[0]
            if s.startswith(("/*", "//")) or not re.match(r"[A-Za-z_]", s):
                return s
            t = self.l6.named(s) if " " in s else (self.l6.named(s) if s not in CKW else None)
            if not t or t[0] != "agg" or self.l5.named(s) == t and s in self.l5.tdef:
                return s
            c = self.map.get(t[1])
            return self.l5.names[c][0] if c else "void"
        text = re.sub(r'/\*.*?\*/|//[^\n]*|(?<![.>\w])(?:(?:struct|union)\s+)?[A-Za-z_]\w*', respell, text, flags=re.S)
        if self.used and "M2C_FIELD(expr" not in text:
            text = text.replace('#include "types.h"\n', '#include "types.h"\n' + M2C_DEF + "\n", 1)
        return text


def pclose(s, i):
    """Index of the parenthesis closing s[i] == '(', or None."""
    d = 0
    for j in range(i, len(s)):
        d += (s[j] == "(") - (s[j] == ")")
        if d == 0:
            return j
    return None


def derefs(s):
    """(start, end, cast type without spaces, address text) of every `(*(T)addr)` in s."""
    for m in re.finditer(r"\(\s*\*\s*\(", s):
        o, t = m.start(), m.end() - 1
        tc, oc = pclose(s, t), pclose(s, o)
        if tc is not None and oc is not None and tc < oc:
            yield o, oc + 1, re.sub(r"\s+", "", s[t + 1:tc]), s[tc + 1:oc]


def scratch_names(text, ents, addr):
    """`(*(T)A)` with A a scratchpad constant (after X6 arithmetic macros such as SP() expand) -> its include/addr.h
    name (`D_<A>`, or `D_<A>.<member>` of its union of views; another type T -> `(*(T)&D_<A>)`, cast through the
    name); an object-like macro left naming only that is dropped and its uses renamed; `#include "addr.h"` added.
    Unknown addresses stay (the readability scan flags them)."""
    fm = {m[1]: (m[2], m[3]) for e in ents if e["kind"] == "macro"
          for m in [re.match(r"#\s*define\s+(\w+)\((\w+)\)\s*(.*)$", e["text"], re.S)] if m}
    names, base = {}, {}
    for m in re.finditer(r"^#define\s+(D_\w+)\s+(.*)$", addr, re.M):
        for _, _, ty, a in derefs(m[2]):
            names[int(a.strip(), 16), ty] = base[int(a.strip(), 16)] = m[1]
            u = re.search(r"typedef union \{([^}]*)\}\s*" + re.escape(m[1]) + r"_t\s*;", addr)
            if u and ty == f"{m[1]}_t*":
                for mt, mn in re.findall(r"([^;]*?)\s*\b(\w+)\s*;", u[1]):
                    names[int(a.strip(), 16), re.sub(r"\s+", "", mt) + "*"] = f"{m[1]}.{mn}"

    def value(a):
        for _ in range(4):
            a = re.sub(r"\b(\w+)\s*\(([^()]*)\)", lambda m: "(" + re.sub(rf"\b{fm[m[1]][0]}\b", "(" + m[2] + ")",
                                                                          fm[m[1]][1]) + ")" if m[1] in fm else m[0], a)
        try:
            return Layout.dim(a)
        except (ValueError, SyntaxError, ZeroDivisionError):
            return None
    hit = True
    while hit:
        hit = next(((o, e, names[v, ty] if (v, ty) in names else f"{text[o:e - 1 - len(a)]}&{base[v]})")
                    for o, e, ty, a in derefs(text) if (v := value(a)) is not None and v in base), None)
        if hit:
            text = text[:hit[0]] + hit[2] + text[hit[1]:]
    for m in list(re.finditer(r"^[ \t]*#[ \t]*define[ \t]+(\w+)[ \t]+(\S+)[ \t]*\n", text, re.M)):
        if m[2] in names.values() and m[2] in text:
            text = re.sub(rf"\b{m[1]}\b", m[2], text.replace(m[0], "", 1))
    if any(n in text for n in names.values()) and '#include "addr.h"' not in text:
        text = text.replace('#include "types.h"\n', '#include "types.h"\n#include "addr.h"\n', 1)
    return text


def fake_pins(text):
    """Mark every register pin (`register ... asm("$n")`) with the `// !FAKE:` line the readability scan asks for."""
    out = []
    for ln in text.splitlines():
        m = re.match(r'(\s*)register\b[^;]*?\b(\w+)\s*(?:asm|__asm__)\s*\(\s*"(\$\w+)"', ln)
        if m and "!FAKE" not in ln and not (out and "!FAKE" in out[-1]):
            out.append(f"{m[1]}// !FAKE: pins {m[2]} to {m[3]}; gcc 2.7.2 allocates another register without it "
                       "(byte mismatch)")
        out.append(ln)
    return "\n".join(out) + "\n"


def fake_gotos(text):
    """Mark every `goto L;` with the `// !FAKE:` comment on its line that psxd_floor.py's debt gate asks for."""
    return re.sub(r"^(.*\bgoto\s+\w+\s*;.*)$", lambda m: m[1] if "!FAKE" in m[1] else
                  m[1] + " // !FAKE: control flow kept from the mmx6 twin", text, flags=re.M)


def inline_fnptrs(text):
    """Drop every function-pointer typedef (`typedef R (*T)(A);`, shapes.py refuses it) and spell R (*...)(A) at
    each use of T: a declarator `T *p[n]` -> `R (**p[n])(A)`, a function `T f(x)` -> `R (*f(x))(A)`, a cast `(T)`."""
    for m in list(re.finditer(r"^[ \t]*typedef\s+([^;()]+?)\s*\(\s*\*\s*(\w+)\s*\)\s*(\([^;]*\))\s*;[ \t]*\n", text,
                              re.M)):
        r, t, a = m[1], m[2], m[3]
        text = text.replace(m[0], "", 1)
        while u := re.search(rf"\b{t}\b\s*((?:\*\s*)*)(\w*)", text):
            stars, name, end = u[1].replace(" ", ""), u[2], u.end()
            if name and text[end:].lstrip().startswith("("):
                c = pclose(text, text.index("(", end))
                name, end = text[u.start(2):c + 1], c + 1
            elif name:
                d = re.match(r"(\s*\[[^\]]*\])*", text[end:])
                name, end = name + d[0].replace(" ", ""), end + d.end()
            text = f"{text[:u.start()]}{r} (*{stars}{name}){a}{text[end:]}"
    return text


def inline_scalars(text):
    """Drop every scalar typedef (`typedef s32 T;`, `typedef u8* T;`, `typedef void* T;`: shapes.py refuses a second
    definition across drafts) and spell its base type at each use of T."""
    for m in list(re.finditer(r"^[ \t]*typedef\s+((?:const\s+)?(?:[us](?:8|16|32)\s*\**|void\s*\*+))\s*(\w+)\s*;[ \t]*\n",
                              text, re.M)):
        text = re.sub(rf"\b{m[2]}\b", re.sub(r"\s*\*", "*", m[1]).strip(), text.replace(m[0], "", 1))
    return text


def port_text(x6, lead, pin, x5types, lines):
    """X6 lead file -> X5 draft text (None, 'map' when the map or the lead name is absent from the X6 file)."""
    src = (x6 / lead["path"]).read_text()
    code = uncomment(src)
    if not re.search(rf"^[A-Za-z_][\w\s*]*\b{lead['name']}\s*\([^;{{]*\)\s*\{{", code, re.M) or \
            any(not re.search(rf"\b{re.escape(k)}\b", code) for k, _ in lead["map"]):
        return None, "map"
    ents = [e for h in X6_HDRS if (x6 / h).exists() for e in c_entities((x6 / h).read_text())]
    ents5 = c_entities(x5types)
    x5 = {n for e in ents5 for n in e["names"]}
    lay6, lay5 = CTypes(ents), CTypes(ents5)
    owner = {}
    for i, e in enumerate(ents):
        for n in e["names"]:
            owner.setdefault(n, i)

    def agg(e):  # an aggregate definition or a typedef naming one: Port maps it onto types.h, never emitted
        return e["kind"] == "decl" and ("{" in e["text"] and re.match(r"(?:typedef\s+)?(?:struct|union)\b", e["text"])
                                        or any((t := lay6.named(n)) and t[0] == "agg" for n in e["names"]))
    keep, todo = set(), list(c_refs(code))
    while todo:
        i = owner.get(todo.pop())
        if i is None or i in keep or ents[i]["names"] & x5 or agg(ents[i]):
            continue
        keep.add(i)
        todo += c_refs(ents[i]["text"])
    block = [ents[i]["text"] for i in sorted(keep)]
    body = []
    for ln in src.splitlines():
        inc = re.match(r'\s*#\s*include\s+"([^"]+)"', ln)
        if inc and inc[1] == "common.h":
            body += ['#include "types.h"'] + block
        elif not (inc and inc[1] in X6_DROP):
            body.append(ln)
    text = "\n".join(body) + "\n"
    defs = set(re.findall(r"#\s*define\s+(\w+)", text)) | {n for e in ents for n in e["names"]} | x5
    declared = set(re.findall(r"^[A-Za-z_][\w\s*]*?\b(\w+)\s*\([^;{]*\)\s*[;{]", uncomment(text), re.M))
    if lead["map"]:
        mp = dict(lead["map"])
        text = re.sub(r"\b(" + "|".join(map(re.escape, mp)) + r")\b", lambda m: mp[m[1]], text)
        defs, declared = {mp.get(n, n) for n in defs}, {mp.get(n, n) for n in declared}
    protos = []
    for c in dict.fromkeys(re.findall(r"\b([A-Za-z_]\w*)\s*\(", uncomment(text))):
        if c in CKW or c in defs or c in declared:
            continue
        cnt = callee_consensus(c, lines)
        if cnt:
            protos.append(cnt.most_common(1)[0][0])
    if protos:
        text = text.replace('#include "types.h"\n', '#include "types.h"\n' + "\n".join(protos) + "\n", 1)
    text = Port(lay6, lay5, text).run()
    addr = x6.parents[1] / "include/addr.h"  # x6 = <root>/refs/mmx6
    addr = addr.read_text() if addr.exists() else ""
    text = re.sub(r"^[ \t]*#[ \t]*define(?:[^\n]*\\\n)+[^\n]*", lambda m: re.sub(r"[ \t]*\\\n[ \t]*", " ", m[0]),
                  text, flags=re.M)  # a `\` continued #define joined onto one line (the readability scan refuses `\`)
    text = fake_gotos(inline_fnptrs(fake_pins(scratch_names(text, ents, addr))))
    text = inline_scalars(re.sub(r"(?<!signed )(?<!unsigned )\bchar\b", "u8", text))
    return f"/* Adapted from mmx6 @{pin[:7]} {lead['path']}, AGPL-3.0 (THIRD_PARTY.md). */\n" + text, None


def x5_known(root, alias):
    """Every X5 data symbol name: DSYM matches in asm/<alias>/**.s, src/<alias>/**.c, include/*.h."""
    fs = [*(root / "asm" / alias).rglob("*.s"), *(root / "src" / alias).rglob("*.c"), *(root / "include").glob("*.h")]
    return {s for f in fs for s in DSYM.findall(f.read_text(errors="replace"))}


def x5_addrs(seed, t):
    """{(symbol, byte addend): X5 address} of the draft's HI16/LO16 pairs, read off the target bytes; {} when it
    does not compile. Our .o carries the addend in the instruction (REL); the target carries the X5 address."""
    import probe
    import reconcile
    obj, _ = probe.compile_obj(Path(seed).resolve(), f"wave/{t['alias']}_{t['name']}", reconcile.triple())
    if obj is None:
        return {}
    d = obj.read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    sh = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    nm = lambda off, base: d[base + off: d.index(b"\0", base + off)].decode()  # noqa: E731
    secs = {nm(s[0], sh[shstrndx][4]): s for s in sh}
    if ".rel.text" not in secs:
        return {}
    sym, strtab, value = secs[".symtab"], sh[secs[".symtab"][6]][4], None
    syms = [struct.unpack_from("<IIIBBH", d, sym[4] + k * 16) for k in range(sym[5] // 16)]
    for s in syms:
        if nm(s[0], strtab) == t["name"]:
            value, size = s[1], s[2]
    if value is None:
        return {}
    ours = d[secs[".text"][4] + value: secs[".text"][4] + value + size]
    tb = probe.target_bytes({"alias": t["alias"], "module": unit(t), "vram": int(t["vram"], 16), "size": size})
    w = lambda b, o: struct.unpack_from("<I", b, o)[0] if o + 4 <= len(b) else 0  # noqa: E731
    sx = lambda x: (x & 0xFFFF) - ((x & 0x8000) << 1)  # noqa: E731
    out, hi = {}, {}
    rel = secs[".rel.text"]
    for k in range(rel[5] // 8):
        off, info = struct.unpack_from("<II", d, rel[4] + k * 8)
        s = nm(syms[info >> 8][0], strtab)
        if not value <= off < value + size or not DSYM.fullmatch(s):
            continue
        o = off - value
        if info & 0xFF == 5:  # R_MIPS_HI16
            hi[s] = o
        elif info & 0xFF == 6 and s in hi:  # R_MIPS_LO16
            a = ((w(ours, hi[s]) & 0xFFFF) << 16) + sx(w(ours, o))
            out[s, a] = (((w(tb, hi[s]) & 0xFFFF) << 16) + sx(w(tb, o))) & 0xFFFFFFFF
    return out


def remap_symbols(text, t, known, addrs):
    """Every data symbol of text absent from known -> its X5 name (`D_<A>_<unit>` or `D_<A>`, known) via addrs;
    uses `S [+ N]` pair with the relocated byte addends in ascending order. -> (text, first unmapped symbol | None)."""
    for s in sorted(set(DSYM.findall(uncomment(text))) - known):
        decl = re.search(rf"^[ \t]*extern\b[^;\n]*\b{s}\b[^;\n]*;[ \t]*\n", text, re.M)
        body = text.replace(decl[0], "") if decl else text
        uses = sorted({int(n or "0", 0) for n in re.findall(rf"\b{s}\b(?:\s*\+\s*(0[xX][0-9A-Fa-f]+|\d+))?", body)})
        ads = sorted(a for x, a in addrs if x == s)
        if len(uses) != len(ads):
            return text, s
        new = {}
        for n, a in zip(uses, ads):
            x = addrs[s, a]
            new[n] = next((c for c in (f"D_{x:08X}_{unit(t)}", f"D_{x:08X}") if c in known), None)
            if new[n] is None:
                return text, s
        if decl:
            text = text.replace(decl[0], "".join(re.sub(rf"\b{s}\b", c, decl[0]) for c in dict.fromkeys(new.values())))
        text = re.sub(rf"\b{s}\b(?:\s*\+\s*(0[xX][0-9A-Fa-f]+|\d+))?", lambda m: new[int(m[1] or "0", 0)], text)
    return text, None


def cmd_port(root, waves, wave, target=None, pin=""):
    wj = Path(waves) / wave / "wave.json"
    if not wj.exists():
        print(f"port: refused -- {wj} missing")
        return 1
    w = World(root)
    x5types = (root / "include/types.h").read_text() if (root / "include/types.h").exists() else ""
    lines, n, m, known = src_lines(root), 0, 0, {}
    for t in json.loads(wj.read_text())["targets"]:
        key = f"{t['alias']}_{t['name']}"
        if target and key != target:
            continue
        lead = w.lead(t)
        if not lead:
            print(f"port: {key} no-lead")
            continue
        n += 1
        text, err = port_text(root / "refs/mmx6", lead, pin, x5types, lines)
        if err:
            print(f"port: {key} error {err}")
            continue
        seed = root / ".run/wave" / wave / "port" / f"{key}.c"
        seed.parent.mkdir(parents=True, exist_ok=True)
        seed.write_text(text)
        if t["alias"] not in known:
            known[t["alias"]] = x5_known(root, t["alias"])
        if set(DSYM.findall(uncomment(text))) - known[t["alias"]]:  # X6 data symbols -> X5 names, or refused
            text, miss = remap_symbols(text, t, known[t["alias"]], x5_addrs(seed, t))
            if miss:
                seed.unlink()
                print(f"port: {key} error symbol {miss}")
                continue
            seed.write_text(text)
        res, _, _ = try_draft(seed, t)
        if res == "match":
            m += 1
            dst = Path(waves) / wave / "drafts" / f"{key}.c"
            dst.parent.mkdir(parents=True, exist_ok=True)
            seed.replace(dst)
        print(f"port: {key} {res}")
    print(f"port: {wave} {m} of {n} leads matched")
    return 0


def seed_extract(f, name):
    """Lines of `name` from glabel to endlabel; a nonmatchings file is taken whole (keeps its jtbl rodata)."""
    lines = f.read_text(errors="replace").splitlines()
    if "nonmatchings" in f.parts:
        return lines
    out, on = [], False
    for ln in lines:
        t = ln.split()
        if t[:2] == ["glabel", name]:
            on = True
        if on:
            out.append(ln)
            if t[:2] == ["endlabel", name]:
                break
    return [".section .text"] + out


def seed_prep(lines):
    """splat/spimdisasm syntax -> m2c input: drop offset comments, macro.inc pseudo-ops, .set/.include."""
    out = []
    for ln in lines:
        ln = re.sub(r"/\*.*?\*/", "", ln).split("#", 1)[0].rstrip()
        t = ln.split()
        if not t or t[0] in (".set", ".include", "nonmatching", "endlabel", "enddlabel"):
            continue
        if t[0] in ("glabel", "dlabel", "jlabel"):
            ln = f"glabel {t[1]}" if t[0] != "jlabel" else f"{t[1]}:"
        out.append(ln)
    return "\n".join(out) + "\n"


def seed_m2c(root, s, name):
    """Raw m2c on prepped asm s -> (C text, None) | (None, why). No --context: m2c rejects types.h directives."""
    r = subprocess.run([str(root / ".venv/bin/python"), str(root / "refs/m2c/m2c.py"), "-t", "mipsel-gcc-c",
                        "-f", name, str(s)], capture_output=True, text=True)
    if r.returncode or not r.stdout.strip():
        why = next((x for x in (r.stderr + r.stdout).splitlines() if x.strip() and x.strip() not in ("/*", "*/")),
                   "no output")
        return None, f"m2c rc={r.returncode}: {why}"
    return '#include "types.h"\n\n' + r.stdout, None


def cmd_seed(root, waves, wave, target=None):
    wj = Path(waves) / wave / "wave.json"
    if not wj.exists():
        print(f"seed: refused -- {wj} missing")
        return 1
    if not (root / "refs/m2c/m2c.py").exists() or not (root / ".venv/bin/python").exists():
        print("seed: m2c missing (bash tools/refs_fetch.sh m2c)")
        return 2
    idx, out = {}, root / ".run/wave" / wave / "seed"
    for t in json.loads(wj.read_text())["targets"]:
        alias, name = t["alias"], t["name"]
        key = f"{alias}_{name}"
        if target and key != target:
            continue
        if alias not in idx:
            idx[alias] = asm_index(root, alias)
        f = idx[alias].get(name) or next(iter(sorted((root / "asm" / alias / "nonmatchings").rglob(f"{name}.s"))),
                                         None)
        if f is None:
            print(f"seed: {key} failed no asm")
            continue
        out.mkdir(parents=True, exist_ok=True)
        s = out / f"{key}.s"
        s.write_text(seed_prep(seed_extract(f, name)))
        c, why = seed_m2c(root, s, name)
        if why:
            print(f"seed: {key} failed {why}")
            continue
        (out / f"{key}.c").write_text(c)
        print(f"seed: {key} emitted ({len(c.splitlines()) - 2} lines)")
    return 0


def wave_dirs(waves):
    """Every waves/W<k>/ dir name, k ascending."""
    return sorted((p.name for p in Path(waves).glob("W*") if p.is_dir() and p.name[1:].isdigit()),
                  key=lambda n: int(n[1:]))


def status_counts(wdir):
    """-> (drafts, banked, failed, no-verdict, drafts without a verdict row) over waves/W<k>/."""
    drafts = {tuple(p.stem.split("_", 1)) for p in (wdir / "drafts").glob("*.c")}
    vp = wdir / "verdicts.jsonl"
    rows = jsonl(vp) if vp.exists() else []
    c = Counter(r["verdict"] for r in rows)
    missing = sorted(drafts - {(r["alias"], r["name"]) for r in rows})
    return len(drafts), c["banked"], c["failed"], c["no-verdict"], missing


def cmd_status(waves, wave, drafts_only=False):
    if wave is None:
        ws = wave_dirs(waves)
        return max([cmd_status(waves, w, drafts_only) for w in ws] or [1])
    wdir = Path(waves) / wave
    if drafts_only:
        targets = json.loads((wdir / "wave.json").read_text())["targets"]
        ap = wdir / "attempts.jsonl"
        # T2 rows {alias,name,...}; T4 rows {target="<alias>_<name>",...}
        tried = {r.get("target") or f"{r['alias']}_{r['name']}" for r in jsonl(ap)} if ap.exists() else set()
        n = sum((wdir / "drafts" / f"{t['alias']}_{t['name']}.c").exists() and f"{t['alias']}_{t['name']}" in tried
                for t in targets)
        print(f"wave: {wave} {n} of {len(targets)} targets drafted")
        return 0 if n == len(targets) else 1
    d, b, f, n, missing = status_counts(wdir)
    for a, nm in missing:
        print(f"wave: no verdict row {a}_{nm}")
    print(f"wave: {wave} {d} drafts = {b} banked + {f} failed + {n} no-verdict")
    return 0 if d == b + f + n and not missing else 1


ROUTE = re.compile(r"^route: (\S+) (draft|draft-twin|defer) cap (\d+) tries")


def r3(bi, ai):  # R3: insns banked rate >= 50% draft, 20-50% draft-twin, < 20% defer.
    return "draft" if bi * 2 >= ai else "draft-twin" if bi * 5 >= ai else "defer"


def rate_per(wdir, per):
    """Add waves/W<k>/'s per-bucket [bi, ai, bh, ah, ctx] into per (a wave without wave.json adds nothing)."""
    wj, vp = wdir / "wave.json", wdir / "verdicts.jsonl"
    targets = json.loads(wj.read_text())["targets"] if wj.exists() else []
    verdict = {f"{r['alias']}_{r['name']}": r["verdict"] for r in (jsonl(vp) if vp.exists() else [])}
    ap = wdir / "attempts.jsonl"
    ctx = Counter()  # T2 rows {alias,name,...}; T4 rows {target="<alias>_<name>",...} (as status)
    for r in jsonl(ap) if ap.exists() else []:
        ctx[r.get("target") or f"{r['alias']}_{r['name']}"] += r.get("ctx_k") or 0
    for t in targets:
        k = f"{t['alias']}_{t['name']}"
        s = per.setdefault(t["bucket"], [0, 0, 0, 0, 0.0])  # bi ai bh ah ctx
        won = verdict.get(k) == "banked"
        s[0] += t["insns"] * won
        s[1] += t["insns"]
        s[2] += won
        s[3] += 1
        s[4] += ctx[k]
    return per


def cmd_rate(waves, wave, check=False, routing=ROOT / "docs/routing.md"):
    per, ws = {}, [wave] if wave else wave_dirs(waves)
    if not ws:
        print("rate: no waves")
        return 1
    for w in ws:
        rate_per(Path(waves) / w, per)
    order = sorted(per.items(), key=lambda kv: (kv[0].startswith(">"), kv[0]))  # A..D, then the >last-bound lane
    lines = [f"rate: {b} {bi} of {ai} insns banked, {bh} of {ah} heads, "
             f"{(c / bi if bi else 0):.2f} k ctx per banked insn" for b, (bi, ai, bh, ah, c) in order]
    unmeasured = ">200" not in per  # a drawn >200 target (heads > 0) is measured like A-D
    if unmeasured:
        lines.append("rate: >200 unmeasured, 0 of 0 heads")
    if wave:
        (Path(waves) / wave / "rate.txt").write_text("\n".join(lines) + "\n")
    print("\n".join(lines))
    if not check:
        return 0
    text = Path(routing).read_text().splitlines() if Path(routing).exists() else []
    got = {m[1]: m[2] for m in map(ROUTE.match, text) if m}
    bad = 0
    for b, (bi, ai, *_) in order:
        if b in got and got[b] != r3(bi, ai):
            print(f"routing: {b} routed {got[b]}, R3 says {r3(bi, ai)}")
            bad += 1
    r = sum(b in got for b in per)
    if unmeasured:  # `unmeasured` route required only while no wave measured >200
        r += any(x.startswith("route: >200") and "unmeasured" in x for x in text)
    m = len(per) + unmeasured
    print(f"routing: {r} of {m} buckets routed")
    return 0 if r == m and not bad else 1


def selftest():
    tmp = ROOT / ".run/wave/selftest"
    shutil.rmtree(tmp, ignore_errors=True)
    shutil.copytree(FIX, tmp, copy_function=shutil.copy)  # fresh mtimes: not stale

    def call(f, *a):
        b = io.StringIO()
        with contextlib.redirect_stdout(b):
            rc = f(*a)
        return rc, b.getvalue()

    rc, out = call(cmd_draw, tmp, "W0", 5, [20])
    assert rc == 0 and "wave: W0 drew 5 targets, 0 invalid" in out, out
    got = [t["name"] for t in json.loads((tmp / "waves/W0/wave.json").read_text())["targets"]]
    assert got == ["fa", "fd", "ff", "ra", "rb"], got  # planted: fb_c status c, fc_noasm no .s, fe_twin, fg excluded
    # strata unchanged by --order leverage: this exact list (and order) is the pre-leverage draw
    assert sum(int(x.split()[-1]) for x in out.splitlines() if x.startswith("lane:")) == 12, out
    w = World(tmp)
    for n in ("fb_c", "fc_noasm", "fg"):
        assert w.invalid(w.dr[("slus", n)], set()), n
    assert w.invalid(w.dr[("slus", "fe_twin")], {w.find(("slus", "fa"))}) == "cluster"
    assert call(cmd_draw, tmp, "W0", 5, [20])[0] == 1  # no overwrite
    assert "bucket A" in call(cmd_draw, tmp, "W1", 6, [20])[1]  # pool too small
    names = lambda wk: [t["name"] for t in json.loads((tmp / f"waves/{wk}/wave.json").read_text())["targets"]]
    rc, out = call(cmd_draw, tmp, "W3", 5, [20], "leverage", 5)
    assert rc == 0 and names("W3") == ["big", "fa", "fd", "ra", "rb"], (out, names("W3"))  # unrouted: big leads
    (tmp / "docs/routing.md").write_text("route: A draft cap 5 tries\nroute: >20 defer cap 3 tries\n")
    rc, out = call(cmd_draw, tmp, "W4", 5, [20], "leverage", 5)
    assert rc == 0 and "wave: W4 drew 5 targets, 0 invalid" in out and "lane:" in out, out
    assert names("W4") == ["fa", "fd", "ff", "ra", "rb"], names("W4")  # planted: big in a defer bucket, not drawn
    (tmp / "docs/routing.md").write_text("route: A draft cap 5 tries\nroute: >20 draft-twin cap 3 tries\n")
    rc, out = call(cmd_draw, tmp, "W5", 5, [20], "leverage", 5)
    assert rc == 0 and "big" not in names("W5"), out  # draft-twin: big has no banked twin, no lever
    with (tmp / LEADS).open("a") as f:  # planted: big gets an X6 lead
        f.write("slus\t0x80001900\tbig\t30\trock_45\t0x800FB54C\tfunc_800FB54C\tsrc/rock_45/FA000.c\tfunc_800FB54C=big\n")
    rc, out = call(cmd_draw, tmp, "W6", 5, [20], "leverage", 5)
    assert rc == 0 and "big" in names("W6"), out  # draft-twin: an X6 lead qualifies big
    (tmp / "docs/routing.md").write_text("route: A draft cap 5 tries\nroute: >20 defer cap 3 tries\n")
    rc, out = call(cmd_draw, tmp, "W7", 5, [20], "port-x6", 5)
    assert rc == 0 and names("W7") == ["big", "fd", "rb", "fa", "ra"], (out, names("W7"))  # leads first, defer lifted
    (tmp / "docs/routing.md").unlink()
    rc, out = call(cmd_card, tmp, "W0")
    assert rc == 0 and "card: W0 5 packs, 0 refused" in out, out
    c = (tmp / ".run/wave/W0/packs/slus_fd/card.md").read_text()
    assert "src/slus/fbank.c" in c and "fbank: 1x `int fbank(int a);`" in c, c
    assert "- addu_ret" in (tmp / ".run/wave/W0/packs/slus_ff/card.md").read_text()
    assert "## Twin in X6\nX6 SLUS_013.95 func_80020000 (0x80020000)" in c and "  - `g_six` -> `g_five`" in c and \
        "`refs/mmx6/src/shared/SLUS_013.95/func_80020000.c`" in c, c
    assert "## Twin in X6\nnone\n" in (tmp / ".run/wave/W0/packs/slus_fa/card.md").read_text()
    assert "`func_800EE9A0` -> `rb`" in (tmp / ".run/wave/W0/packs/rockx5_rb/card.md").read_text()  # overlay key
    assert (tmp / ".run/wave/W0/packs/slus_fa/target.s").is_symlink()
    (tmp / "docs/ledger.md").write_text("- slus_fa fa lever:bogus_lever see C9999\n")
    rc, out = call(cmd_card, tmp, "W0")
    assert rc == 1 and "unresolved bogus_lever C9999" in out, out
    os.utime(tmp / TWINS, (0, 0))
    rc, out = call(cmd_draw, tmp, "W2", 5, [20])
    assert rc == 1 and TWINS in out, out
    wd = tmp / "waves/W0"  # rate: fa banked (insns from draw), ra failed; others no row
    (wd / "verdicts.jsonl").write_text('{"alias":"slus","name":"fa","verdict":"banked"}\n'
                                       '{"alias":"rockx5","name":"ra","verdict":"failed"}\n')
    (wd / "attempts.jsonl").write_text('{"target":"slus_fa","ctx_k":10}\n{"alias":"rockx5","name":"ra","ctx_k":5}\n')
    rc, out = call(cmd_rate, tmp / "waves", "W0")
    assert rc == 0 and out.count("rate:") == 2 and "1 of 5 heads" in out, out
    bi, ai = (int(x) for x in re.search(r"rate: A (\d+) of (\d+)", out).groups())
    route = tmp / "routing.md"
    for wrong in ("draft", "draft-twin", "defer"):
        if wrong != r3(bi, ai):
            break
    route.write_text(f"route: A {wrong} cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", "W0", True, route)
    assert rc == 1 and "R3 says" in out, out  # planted wrong route refused
    route.write_text(f"route: A {r3(bi, ai)} cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", "W0", True, route)
    assert rc == 0 and "routing: 2 of 2 buckets routed" in out, out
    rt = (wd / "rate.txt").read_text()  # aggregate (R5): A summed over every wave, no rate.txt written
    ws = wave_dirs(tmp / "waves")
    assert len(ws) > 1 and not (tmp / "waves" / ws[-1] / "rate.txt").exists(), ws
    agg = call(cmd_rate, tmp / "waves", None)[1]
    abi, aai = (int(x) for x in re.search(r"rate: A (\d+) of (\d+)", agg).groups())
    assert abi == bi and aai > ai and (wd / "rate.txt").read_text() == rt, agg
    route.write_text(f"route: A {r3(abi, aai)} cap 3 tries\nroute: >20 defer cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves", None, True, route)  # W3's leverage draw adds bucket >20 (big, unbanked)
    assert rc == 0 and "routing: 3 of 3 buckets routed" in out and f"A {abi} of {aai}" in out, out
    mw = tmp / "waves200/W9"  # measured >200: one line, after A..D, replaces `unmeasured`; routed by R3
    mw.mkdir(parents=True)
    (mw / "wave.json").write_text(json.dumps({"targets": [
        {"alias": "slus", "name": "h", "insns": 300, "bucket": ">200"},
        {"alias": "slus", "name": "a", "insns": 10, "bucket": "A"}]}))
    (mw / "verdicts.jsonl").write_text('{"alias":"slus","name":"h","verdict":"banked"}\n')
    rc, out = call(cmd_rate, tmp / "waves200", "W9")
    rl = (mw / "rate.txt").read_text().splitlines()
    assert rc == 0 and len(rl) == 2 and rl[0].startswith("rate: A ") and rl[1].startswith("rate: >200 300 of 300"), rl
    route.write_text("route: A defer cap 3 tries\nroute: >200 defer cap 3 tries\nroute: >200 unmeasured\n")
    rc, out = call(cmd_rate, tmp / "waves200", "W9", True, route)
    assert rc == 1 and "routing: >200 routed defer, R3 says draft" in out and "of 2 buckets" in out, out
    route.write_text("route: A defer cap 3 tries\nroute: >200 draft cap 3 tries\n")
    rc, out = call(cmd_rate, tmp / "waves200", "W9", True, route)
    assert rc == 0 and "routing: 2 of 2 buckets routed" in out, out
    rc, out = call(cmd_status, tmp / "waves", None)
    assert rc == 1 and [x.split()[1] for x in out.splitlines()] == ws, out  # W0: rows, no drafts -> fails all
    assert call(cmd_rate, tmp / "none", None)[0] == 1 and call(cmd_status, tmp / "none", None)[0] == 1
    print("wave: control OK -- invalid target refused")
    w = World(tmp)  # port: fd's lead (fixture refs/mmx6, includes mmx6/x4.h) rewritten for X5
    pt, err = port_text(tmp / "refs/mmx6", w.lead(w.dr[("slus", "fd")]), "0123456789", (tmp / "include/types.h")
                        .read_text(), src_lines(tmp))
    assert err is None and pt.startswith("/* Adapted from mmx6 @0123456 src/shared/SLUS_013.95/func_80020000.c, "
                                         "AGPL-3.0 (THIRD_PARTY.md). */\n/* Adapted from sozud/mmx4 "), pt
    assert "mmx6/" not in pt.split("*/", 2)[2] and '#include "types.h"' in pt and "int fbank(int a);" in pt, pt
    assert "#define SIX_OBJ(o) ((X4_Thing*)(o))" in pt and "SIX_OBJ(o)->y_pos = v + M2C_FIELD(q, s32*, 0x0);" in pt \
        and "void* q" in pt and "Fx6Only" not in pt and "s32 v = g_five;" in pt and "void fd(void* o)" in pt and "g_five" in pt, pt
    assert "u8 c = 1;" in pt and not re.search(r"struct X4_|union \{", pt), pt  # types.h shape, no local structs
    assert not re.search(r"X4_Unused|X4_RECT|Fx6Unused|typedef \w+ (u8|s8|s16|s32);|s32 big", pt), pt  # untouched
    print("wave: control OK -- mmx6 closure rewritten to the types.h shape")
    assert "        goto out; // !FAKE: control flow kept from the mmx6 twin\n" in pt, pt  # planted goto
    print("wave: control OK -- mmx6 goto emitted marked !FAKE")
    assert "X4_CdlCB" not in pt and "void (*CdReadyCallback(void (*func)(X4_u_char, X4_u_char*)))(X4_u_char, " \
        "X4_u_char*);" in pt, pt  # planted function-pointer typedef
    print("wave: control OK -- mmx6 function-pointer typedef inlined")
    assert "#define CUR (*(s32**)&D_1F800064)" in pt and '#include "addr.h"' in pt and "0x1F8" not in pt, pt
    print("wave: control OK -- raw scratchpad cast spelled through its addr.h name")
    assert "#define TWICE(a) ((a) + (a))\n" in pt and "\\\n" not in pt, pt  # planted `\` continued #define
    print("wave: control OK -- mmx6 continued #define joined onto one line")
    with (tmp / LEADS).open("a") as f:  # planted: fa's lead maps g_seven, absent from the X6 file
        f.write("slus\t0x80001000\tfa\t4\tSLUS_013.95\t0x80020000\tfunc_80020000\t"
                "src/shared/SLUS_013.95/func_80020000.c\tfunc_80020000=fa;g_seven=g_x\n")
    rc, out = call(cmd_port, tmp, tmp / "waves", "W0", "slus_fa", "0123456789")
    assert rc == 0 and out == "port: slus_fa error map\nport: W0 0 of 1 leads matched\n", out
    assert not (tmp / "waves/W0/drafts").exists() and not (tmp / ".run/wave/W0/port").exists()
    assert call(cmd_port, tmp, tmp / "waves", "W99")[0] == 1
    print("wave: control OK -- mmx6 lead ported (includes rewritten), wrong map refused")
    with (tmp / LEADS).open("a") as f:  # planted: fa's lead reads D_80031234, which no X5 name maps
        f.write("slus\t0x80001000\tfa\t4\tSLUS_013.95\t0x80020200\tfunc_80020200\t"
                "src/shared/SLUS_013.95/func_80020200.c\tfunc_80020200=fa\n")
    global x5_addrs
    real, x5_addrs = x5_addrs, lambda seed, t: {}  # ROM- and toolchain-free: no relocation reads an X5 address
    try:
        rc, out = call(cmd_port, tmp, tmp / "waves", "W0", "slus_fa", "0123456789")
    finally:
        x5_addrs = real
    assert rc == 0 and out == "port: slus_fa error symbol D_80031234\nport: W0 0 of 1 leads matched\n", out
    assert not (tmp / "waves/W0/drafts").exists() and not (tmp / ".run/wave/W0/port/slus_fa.c").exists()
    print("wave: control OK -- unmapped mmx6 data symbol refused")
    sf = tmp / "seed_fix.s"  # hand-written splat-style asm (invented function, no game bytes)
    sf.write_text(".include \"macro.inc\"\n.set noat\nglabel other\n    nop\nendlabel other\nglabel addone\n"
                  "    /* 0 80001000 03E00008 */  jr         $ra\n    /* 4 80001004 24820001 */   addiu      $v0, $a0, 1 # x\n"
                  "jlabel .L1\n    nop\nendlabel addone\n")
    pre = seed_prep(seed_extract(sf, "addone"))
    assert pre == ".section .text\nglabel addone\n      jr         $ra\n       addiu      $v0, $a0, 1\n.L1:\n    nop\n", pre
    assert call(cmd_seed, tmp, tmp / "waves", "W0") == (2, "seed: m2c missing (bash tools/refs_fetch.sh m2c)\n")
    c = None
    if (ROOT / "refs/m2c/m2c.py").exists():
        (tmp / "seed_fix.pre.s").write_text(pre)
        c, why = seed_m2c(ROOT, tmp / "seed_fix.pre.s", "addone")
        assert why is None and "addone(" in c, (why, c)
    print("wave: control OK -- seed asm prepped for m2c" + (", m2c emits it" if c else ""))
    os.utime(tmp / TWINS)  # un-stale (planted mtime 0 above)
    (tmp / "waves/W8").mkdir()  # planted: fd failed (ledgered), fu a rank-null draw row
    (tmp / "waves/W8/verdicts.jsonl").write_text('{"alias":"slus","module":"slus/seg","name":"fd","vram":"80001300",'
                                                 '"verdict":"failed"}\n')
    with (tmp / DRAW).open("a") as f:
        f.write(json.dumps({"alias": "slus", "module": "slus/seg", "name": "fu", "vram": "80001C00", "insns": 4,
                            "verdict": "draw", "reason": None, "rank": None, "reach": 1}) + "\n")
    rc, out = call(cmd_open, tmp, ["A"], [20], True)
    assert rc == 1 and out == "open: A 9 open, 10 drawable, 1 ledgered, 1 unranked\n", out
    assert call(cmd_open, tmp, ["A"], [1, 20], True) == (0, "open: A 0 open, 0 drawable, 0 ledgered\n")
    w = World(tmp)
    assert w.invalid(w.dr[("slus", "fd")], set()) == "ledgered"
    rc, out = call(cmd_draw, tmp, "W10", 5, [20], "leverage", 4, {"A"})  # big (>20) filtered, fd ledgered
    assert rc == 0 and names("W10") == ["fa", "ff", "ra", "rb"] and "exhausted" not in out, (out, names("W10"))
    rc, out = call(cmd_draw, tmp, "W11", 5, [20], "leverage", 6, {"A"})
    assert rc == 0 and "wave: pool exhausted, drew 4 of --size 6" in out and len(names("W11")) == 4, out
    rc, out = call(cmd_draw, tmp, "W12", 5, [20], "leverage", 5, {"B"})
    assert rc == 1 and out == "wave: pool exhausted, drew 0 of --size 5\n" and not (tmp / "waves/W12").exists(), out
    rc, out = call(cmd_open, tmp, [">20"], [20])
    assert rc == 0 and out.startswith("open: >20 ") and not out.startswith("open: >20 0 open"), out
    rc, out = call(cmd_draw, tmp, "W13", 5, [20], "leverage", 6, {"A"}, 2)  # fe_twin shares fa's cluster
    assert rc == 0 and "fe_twin" in names("W13") and "0 invalid" in out, (out, names("W13"))
    print("wave: control OK -- open counts, --only filter, ledgered skipped, pool exhausted, >bound, per-cluster")
    return 0


def main(argv=None):
    if argv is None:
        argv = sys.argv[1:]
    if argv == ["--selftest"]:
        return selftest()
    ap = argparse.ArgumentParser(prog="waves.py")
    sp = ap.add_subparsers(dest="cmd", required=True)
    d = sp.add_parser("draw")
    d.add_argument("wave")
    d.add_argument("--per", type=int, default=6)
    d.add_argument("--buckets", default="20,50,100,200")
    d.add_argument("--order", choices=["strata", "leverage", "port-x6"], default="strata")
    d.add_argument("--size", type=int)
    d.add_argument("--only", help="leverage/port-x6: only these buckets, e.g. A,B")
    d.add_argument("--per-cluster", type=int, default=1, metavar="N",
                   help="with --only: up to N targets per dup cluster (default 1); A/B tail only, when the open "
                        "rows sit in one cluster and a 1-per-cluster draw falls far short of --size")
    o = sp.add_parser("open")
    o.add_argument("names")
    o.add_argument("--check", action="store_true")
    o.add_argument("--buckets", default="20,50,100,200")
    sp.add_parser("card").add_argument("wave")
    t = sp.add_parser("try")
    t.add_argument("draft")
    t.add_argument("--target", required=True)
    s = sp.add_parser("status")
    s.add_argument("wave", nargs="?")
    s.add_argument("--drafts-only", action="store_true")
    s.add_argument("--waves", default=str(ROOT / "waves"))
    r = sp.add_parser("rate")
    r.add_argument("wave", nargs="?")
    r.add_argument("--check", action="store_true")
    p = sp.add_parser("port")
    p.add_argument("wave")
    p.add_argument("--target")
    p.add_argument("--waves", default=str(ROOT / "waves"))
    e = sp.add_parser("seed")
    e.add_argument("wave")
    e.add_argument("--target")
    e.add_argument("--waves", default=str(ROOT / "waves"))
    a = ap.parse_args(argv)
    if a.cmd == "seed":
        return cmd_seed(ROOT, a.waves, a.wave, a.target)
    if a.cmd == "port":
        pin, head = x6_pin(ROOT)
        if pin != head:
            print(f"port: refused -- refs/mmx6 HEAD {head or 'missing'} != config/refs.toml mmx6 ref {pin} "
                  "(bash tools/refs_fetch.sh mmx6)")
            return 1
        return cmd_port(ROOT, a.waves, a.wave, a.target, pin)
    if a.cmd == "rate":
        return cmd_rate(ROOT / "waves", a.wave, a.check)
    if a.cmd == "draw":
        if a.order in ("leverage", "port-x6") and not a.size:
            ap.error(f"--order {a.order} needs --size N")
        if a.only and a.order == "strata":
            ap.error("--only needs --order leverage or port-x6")
        if a.per_cluster != 1 and not a.only:
            ap.error("--per-cluster needs --only")
        if a.per_cluster < 1:
            ap.error("--per-cluster needs N >= 1")
        return cmd_draw(ROOT, a.wave, a.per, [int(x) for x in a.buckets.split(",")], a.order, a.size,
                        set(a.only.split(",")) if a.only else None, a.per_cluster)
    if a.cmd == "open":
        return cmd_open(ROOT, a.names.split(","), [int(x) for x in a.buckets.split(",")], a.check)
    if a.cmd == "card":
        return cmd_card(ROOT, a.wave)
    if a.cmd == "status":
        return cmd_status(a.waves, a.wave, a.drafts_only)
    return cmd_try(a.draft, a.target)


if __name__ == "__main__":
    sys.exit(main())
