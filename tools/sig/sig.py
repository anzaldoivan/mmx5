"""Sig: function signatures, exact tier (equal signature) and near tier (twin band) over the census inventory.

  sig.py band [--sample N] [--pairs P] [--seed S] | --selftest
  sig.py build-foreign --triple mmx4|x5 ; sig.py foreign --objs .run/sig/mmx4/<triple>   (L8; tools/sig/README.md)

Inputs: census.load() (inventory rows + words from the expected bytes; run tools/census/inventory.py and
`census.py dup` first) and .run/census/groups.jsonl. Functions keyed (alias, vram, name) (G41).
Norm words = census.dup_key(words) (reloc fields masked). Signature = sha1 hex of the norm words (LE u32).
Exact cluster = equal signature; its representative = first member by key.
Near tier, between cluster representatives only: dist = unit-cost Levenshtein over norm words; near iff
dist / max(len) < T (T = 3/10) and max(len) >= FLOOR. Prefilter (sound lower bounds on dist): length difference, and
the opcode-histogram bound (|la - lb| + L1(opcode histograms)) / 2. Survivors: banded Levenshtein, band = cutoff
D = largest d with d/max < T; among min-dist alignments the fewest substitutions. work = indels + 3 * substitutions.
Pairs expand arithmetically: a near rep pair stands for |A| * |B| function pairs.

band: writes .run/sig/twins.jsonl (exact: one row per member vs its cluster rep; near: one row per rep pair; sorted by
work then keys; rows {a, b, tier, dist, ratio, sig_a, sig_b, na, nb (insns), work}) and prints
  sig: <n> of <m> functions signed
  sig: band reproduces <r> of <e> exact pairs, +<k> near     (e = sum C(|g|,2) over census dup groups)
  sig: base rate <x>% over <p> random pairs                 (exact or near, fixed seed)
  sig: control OK -- prefilter sound on <p> random pairs    (true distance by bit-parallel Levenshtein, unbanded)
Exit 0 green; 1 = an exact pair missing, n != m, or an unsound prefilter rejection; 2 refused input.
--sample N: the same on a deterministic N-function subset (groups cut to their members inside it).
--selftest: tools/sig/fixtures/functions.json (our own words): reloc-only pair exact, one-substitution pair near
only, a permuted lookalike that passes the prefilter with ratio >= T not paired.
"""
import argparse
import hashlib
import json
import multiprocessing as mp
import os
import random
import struct
import subprocess
import sys
import time
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "census"))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "probe"))
from census import dup_key, group, load  # noqa: E402
from inventory import ROOT  # noqa: E402
from probe import masked, read_func  # noqa: E402

OUT = ROOT / ".run/sig/twins.jsonl"
GROUPS = ROOT / ".run/census/groups.jsonl"
INV = ROOT / ".run/census/inventory.jsonl"
FIXTURE = Path(__file__).resolve().parent / "fixtures/functions.json"
TN, TD = 3, 10   # T = 0.3, the DK-10 lookalike ratio; near iff TD * dist < TN * max(len)
FLOOR = 8        # near needs max(len) >= 8: below it one differing word is already >= 1/8 of the body
BIG = 1 << 20    # DP cost = dist * BIG + subs: min dist first, then fewest substitutions
SEED = 5


def key(f):
    return (f["alias"], f["vram"], f["name"])


def mem(f):
    return {"alias": f["alias"], "name": f["name"], "vram": f["vram"]}


def cutoff(m):
    """Largest dist d with d / m < T."""
    return (TN * m - 1) // TD


def lower_bound(a, b):
    """a, b: (len, opcode Counter). Sound lower bound on Levenshtein dist."""
    l1 = sum(abs(a[1][k] - b[1].get(k, 0)) for k in a[1]) + sum(v for k, v in b[1].items() if k not in a[1])
    return (abs(a[0] - b[0]) + l1) // 2


def banded(a, b, d):
    """Min-dist alignment within |i - j| <= d: (dist, subs), or None when dist > d."""
    n, m = len(a), len(b)
    if abs(n - m) > d:
        return None
    inf = (d + 1) * BIG
    prev = [j * BIG if j <= d else inf for j in range(m + 1)]
    for i in range(1, n + 1):
        cur = [inf] * (m + 1)
        lo, hi = max(1, i - d), min(m, i + d)
        if i <= d:
            cur[0] = i * BIG
        x, best = a[i - 1], cur[0] if i <= d else inf
        for j in range(lo, hi + 1):
            v = prev[j - 1] + (0 if x == b[j - 1] else BIG + 1)
            u = prev[j] + BIG
            if u < v:
                v = u
            u = cur[j - 1] + BIG
            if u < v:
                v = u
            cur[j] = v
            if v < best:
                best = v
        if best // BIG > d:
            return None
        prev = cur
    v = prev[m]
    return None if v // BIG > d else (v // BIG, v % BIG)


def lev(a, b):
    """Unbanded unit-cost Levenshtein, bit-parallel (Myers/Hyyro); independent of banded()."""
    if len(a) < len(b):
        a, b = b, a
    m = len(a)
    if m == 0:
        return len(b)
    peq = defaultdict(int)
    for i, c in enumerate(a):
        peq[c] |= 1 << i
    mask, top = (1 << m) - 1, 1 << (m - 1)
    pv, mv, score = mask, 0, m
    for c in b:
        eq = peq.get(c, 0)
        xv = eq | mv
        xh = (((eq & pv) + pv) ^ pv) | eq
        ph = (mv | ~(xh | pv)) & mask
        mh = pv & xh
        if ph & top:
            score += 1
        elif mh & top:
            score -= 1
        ph = ((ph << 1) | 1) & mask
        mh = (mh << 1) & mask
        pv = (mh | ~(xv | ph)) & mask
        mv = ph & xv
    return score


def near(a, b, pa, pb):
    """a, b: norm words; pa, pb: (len, opcode Counter). -> (verdict, dist, subs); verdict pre|floor|far|near."""
    mx = max(pa[0], pb[0])
    if mx < FLOOR:
        return "floor", None, None
    d = cutoff(mx)
    if lower_bound(pa, pb) > d:
        return "pre", None, None
    r = banded(a, b, d)
    return ("far", None, None) if r is None else ("near", r[0], r[1])


def prof(w):
    return (len(w), Counter(x >> 26 for x in w))


_REPS = None


def _work(i):
    """Near pairs (i, j > i) among reps sorted by length descending; j only while len_j > (1 - T) * len_i."""
    reps, out = _REPS, []
    wi, pi = reps[i][1], reps[i][2]
    for j in range(i + 1, len(reps)):
        pj = reps[j][2]
        if TD * (pi[0] - pj[0]) >= TN * pi[0]:  # length bound alone already >= T: rest are shorter still
            break
        v, d, s = near(wi, reps[j][1], pi, pj)
        if v == "near":
            out.append((i, j, d, s))
    return out


def band(fns, groups, pairs, seed, procs=True):
    """fns: [{alias,name,vram,words}]; groups: census rows. Returns (rc, lines, twins rows)."""
    global _REPS
    keys = [key(f) for f in fns]
    if len(set(keys)) != len(keys):
        return 1, ["sig: FAIL -- duplicate (alias, vram, name) keys"], []
    norm = {key(f): dup_key(f["words"]) for f in fns}
    sig = {k: hashlib.sha1(struct.pack(f"<{len(w)}I", *w)).hexdigest() for k, w in norm.items()}
    cl = defaultdict(list)
    for k in sorted(sig):
        cl[sig[k]].append(k)
    lines = [f"sig: {len(sig)} of {len(fns)} functions signed"]
    rows = []
    for s, ks in cl.items():
        for k in ks[1:]:
            rows.append({"a": dict(zip(("alias", "vram", "name"), ks[0])), "b": dict(zip(("alias", "vram", "name"), k)),
                         "tier": "exact", "dist": 0, "ratio": 0.0, "sig_a": s, "sig_b": s,
                         "na": len(norm[k]), "nb": len(norm[k]), "work": 0})
    # exact check: each dup group, by key, inside one signature cluster (independent of census's own clustering)
    e = r = 0
    miss = []
    for g in groups:
        if g["kind"] != "dup":
            continue
        ks = [(x["alias"], x["vram"], x["name"]) for x in g["members"]]
        ks = [k for k in ks if k in sig]  # --sample: the group cut to its members inside the subset
        c = len(ks) * (len(ks) - 1) // 2
        e += c
        if len({sig[k] for k in ks}) <= 1:
            r += c
        elif c:
            miss.append(g["group"])
    # near tier between reps
    reps = sorted(((ks[0], norm[ks[0]], prof(norm[ks[0]]), s) for s, ks in cl.items()),
                  key=lambda x: (-len(x[1]), x[0]))
    _REPS = reps
    t0 = time.time()
    if procs and len(reps) > 200:
        with mp.get_context("fork").Pool() as pool:
            found = [x for part in pool.imap_unordered(_work, range(len(reps)), chunksize=4) for x in part]
    else:
        found = [x for i in range(len(reps)) for x in _work(i)]
    k_near = 0
    for i, j, d, s in found:
        a, b = sorted((reps[i], reps[j]), key=lambda x: x[0])
        na, nb = len(cl[a[3]]), len(cl[b[3]])
        k_near += na * nb
        mx = max(len(a[1]), len(b[1]))
        rows.append({"a": dict(zip(("alias", "vram", "name"), a[0])), "b": dict(zip(("alias", "vram", "name"), b[0])),
                     "tier": "near", "dist": d, "ratio": round(d / mx, 4), "sig_a": a[3], "sig_b": b[3],
                     "na": len(a[1]), "nb": len(b[1]), "work": d + 2 * s})
    rows.sort(key=lambda x: (x["work"], tuple(x["a"].values()), tuple(x["b"].values())))
    lines.append(f"sig: band reproduces {r} of {e} exact pairs, +{k_near} near")
    lines += [f"sig: FAIL -- dup group {g} split across signatures" for g in miss[:20]]
    print(f"sig: near tier {len(reps)} reps, {len(found)} rep pairs, {time.time() - t0:.1f} s", file=sys.stderr)
    # base rate + control on p random function pairs
    rng = random.Random(seed)
    ks = sorted(sig)
    pr = {k: prof(norm[k]) for k in ks}
    inb = bad = mism = 0
    for _ in range(pairs):
        x, y = rng.sample(ks, 2)
        if sig[x] == sig[y]:
            inb += 1
            continue
        v, d, s = near(norm[x], norm[y], pr[x], pr[y])
        inb += v == "near"
        mx = max(pr[x][0], pr[y][0])
        if v == "floor":
            continue
        true = lev(norm[x], norm[y])
        if v == "pre" and TD * true < TN * mx:
            bad += 1
            lines.append(f"sig: FAIL -- prefilter rejected {x} {y} with true dist {true} of {mx}")
        if (v == "near") != (TD * true < TN * mx) or (v == "near" and d != true):
            mism += 1
            lines.append(f"sig: FAIL -- banded {v} {d} vs true {true} for {x} {y}")
    lines.append(f"sig: base rate {100 * inb / pairs:.4f}% over {pairs} random pairs")
    if bad or mism:
        lines.append(f"sig: control FAIL -- {bad} unsound prefilter rejections, {mism} banded mismatches")
    else:
        lines.append(f"sig: control OK -- prefilter sound on {pairs} random pairs")
    return (1 if miss or r != e or bad or mism else 0), lines, rows


def run_band(sample, pairs, seed):
    t0 = time.time()
    rc, fns, _ = load()
    if rc == 2 or not GROUPS.exists():
        print("sig: refused -- missing census inputs (run inventory.py and census.py dup)")
        return 2
    m = sum(1 for _ in INV.read_text().splitlines())
    groups = [json.loads(x) for x in GROUPS.read_text().splitlines()]
    if sample:
        fns = sorted(fns, key=key)
        fns = sorted(random.Random(seed).sample(fns, min(sample, len(fns))), key=key)
        m = len(fns)
    rc2, lines, rows = band(fns, groups, pairs, seed)
    lines[0] = f"sig: {len(fns)} of {m} functions signed"
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("".join(json.dumps(x) + "\n" for x in rows))
    for x in lines:
        print(x)
    print(f"sig: {time.time() - t0:.1f} s wall", file=sys.stderr)
    return 1 if rc or rc2 or len(fns) != m else 0


# --- L8: foreign (mmx4) leaves into the fleet. refs/mmx4 is AGPL-3.0: compiled to .run/sig/ only, never copied (G12).
MMX4 = ROOT / "refs/mmx4"
FOREIGN = ROOT / ".run/sig/mmx4"
LEAVES = FOREIGN / "leaves.json"
CC = ROOT / "tools/bin/cc"
GAS = ROOT / "tools/bin/mipsel-linux-gnu-as"
MASPSX = ROOT / "refs/maspsx/maspsx.py"
CONTROL = ("src/slus/func_800132F8.c", "func_800132F8", "slus", "800132F8")
LEAF_MAX = 32
PIN_CPP = ["-lang-c", "-D__GNUC__=2", "-Dmips", "-D__mips__", "-Dpsx", "-D__psx__", "-D_MIPSEL",
           "-D__CHAR_UNSIGNED__", "-D__OPTIMIZE__"]  # mk/slus.mk CPPFLAGS (2.95.2 cpp: no -undef)
# mmx4 sources are preprocessed by the host cpp, as mmx4 does (build.py:149 `cpp $CPP_FLAGS`): the psx cpps
# (2.7.2, 2.95.2) reject PsyQ 4.0's CRLF line continuations (LIBGPU.H:82 parse error, "stray '\'").
MMX4_CPP = ["cpp", "-undef", "-DSKIP_ASM=1", "-DVERSION_US=1", f"-I{MMX4 / 'src/snd'}", f"-I{MMX4 / 'include'}"]
TRIPLES = {  # (cc dir, mmx4-source cpp flags, cc1 flags, maspsx flags)
    "mmx4": ("gcc-2.7.2-psx",  # refs/mmx4/build.py:71 cpp, :159 cc1, :163 maspsx
             ["-D__GNUC__=2", "-D__OPTIMIZE__", "-lang-c", "-Dmips", "-D__mips__", "-D__mips", "-Dpsx",
              "-D__psx__", "-D__psx", "-D__EXTENSIONS__", "-D_MIPSEL", "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C",
              "-DLANGUAGE_C"],
             ["-w", "-quiet", "-msoft-float", "-O2", "-g0", "-G0", "-funsigned-char"],
             ["--aspsx-version=2.56", "--expand-div"]),
    "x5": ("gcc-2.95.2-psx", PIN_CPP, ["-O2", "-G0", "-quiet", "-w"], ["--aspsx-version=2.86"]),  # compiler-pin.md
}


def compile_c(src, out, triple, cpp):
    """cpp | cc1 | maspsx | as -> out (.o); intermediates beside it. -> None or the failing stage."""
    cc, _, ccf, msf = TRIPLES[triple]
    out.parent.mkdir(parents=True, exist_ok=True)
    i, s1, s2 = out.with_suffix(".i"), out.with_suffix(".cc.s"), out.with_suffix(".s")
    steps = [("cpp", cpp + [str(src), str(i)], None, None),
             ("cc1", [str(CC / cc / "cc1")] + ccf + [str(i), "-o", str(s1)], None, None),
             ("maspsx", [sys.executable, str(MASPSX)] + msf, s1, s2),
             ("as", [str(GAS), "-EL", "-march=r3000", "-no-pad-sections", "-G0", str(s2), "-o", str(out)], None, None)]
    for stage, cmd, fin, fout in steps:
        with open(fin or "/dev/null", "rb") as fi, open(fout or os.devnull, "wb") as fo:
            r = subprocess.run(cmd, stdin=fi, stdout=fo, stderr=subprocess.PIPE)
        if r.returncode:
            out.with_suffix(".err").write_bytes(r.stderr)
            return stage
    return None


def funcs(obj):
    """[(name, size bytes)] of STT_FUNC symbols in .text of an ELF32 LE .o."""
    d = obj.read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    sh = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    nm = lambda off, base: d[base + off: d.index(b"\0", base + off)].decode()
    secs = {nm(s[0], sh[shstrndx][4]): (i, s) for i, s in enumerate(sh)}
    ti, symtab = secs[".text"][0], secs[".symtab"][1]
    out = []
    for k in range(symtab[5] // 16):
        st_name, _, size, info, _, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + k * 16)
        if shndx == ti and info & 0xF == 2 and size:
            out.append((nm(st_name, sh[symtab[6]][4]), size))
    return out


def is_leaf(words):
    return len(words) <= LEAF_MAX and not any(w >> 26 == 3 or (w >> 26 == 0 and w & 63 == 9) for w in words)


def build_foreign(triple):
    dst = FOREIGN / triple
    srcs = sorted(p.relative_to(MMX4) for p in (MMX4 / "src/main").rglob("*.c"))
    cpp = MMX4_CPP + TRIPLES[triple][1]
    with ThreadPoolExecutor() as ex:
        res = list(ex.map(lambda p: compile_c(MMX4 / p, dst / p.with_suffix(".o"), triple, cpp), srcs))
    fail = [(str(p), st) for p, st in zip(srcs, res) if st]
    for p, st in fail:
        print(f"sig: compile fail [{triple}] {p} at {st}", file=sys.stderr)
    print(f"sig: build-foreign {len(srcs) - len(fail)} of {len(srcs)} mmx4 files compiled [{triple}]")
    st = compile_c(ROOT / CONTROL[0], dst / "control.o", "x5",
                   [str(CC / TRIPLES["x5"][0] / "cpp")] + PIN_CPP + [f"-I{ROOT / 'include'}"])  # the pin, as built
    if st:
        print(f"sig: control FAIL -- {CONTROL[0]} at {st}")
        return 1
    if triple == "mmx4":
        leaves = []
        for p, s in zip(srcs, res):
            if s:
                continue
            o = dst / p.with_suffix(".o")
            for name, _ in funcs(o):
                b, mk = read_func(o, name)
                if is_leaf(masked(b, mk)):
                    leaves.append({"file": str(p), "name": name})
        LEAVES.write_text(json.dumps(leaves, indent=0) + "\n")
        print(f"sig: {len(leaves)} mmx4 leaves (<= {LEAF_MAX} insns, no jal/jalr) -> {LEAVES.relative_to(ROOT)}")
    return 0


def obj_words(o, name):
    """Masked words of `name` in .o `o` (relocated fields zeroed), or None if absent."""
    if not o.exists():
        return None
    try:
        b, mk = read_func(o, name)
    except KeyError:
        return None
    return masked(b, mk)


def foreign(objs):
    objs = Path(objs).resolve()
    tri = objs.name
    if not LEAVES.exists():
        print("sig: refused -- missing .run/sig/mmx4/leaves.json (run build-foreign --triple mmx4)")
        return 2
    rc, fns, _ = load()
    if rc == 2:
        print("sig: refused -- missing census inputs (run inventory.py)")
        return 2
    def sign(w):  # T1's signature: sha1 of the dup_key words (band())
        n = dup_key(w)
        return hashlib.sha1(struct.pack(f"<{len(n)}I", *n)).hexdigest(), n
    cl = defaultdict(list)
    for f in sorted(fns, key=key):
        cl[sign(f["words"])[0]].append(f)
    reps = [(s, dup_key(ms[0]["words"]), ms) for s, ms in cl.items()]
    reps = [(s, w, prof(w), ms) for s, w, ms in reps]
    # control: our own function through the same read/sign/search path
    cw = obj_words(objs / "control.o", CONTROL[1])
    hit = cw is not None and any(m["alias"] == CONTROL[2] and m["vram"].upper() == CONTROL[3]
                                 for m in cl.get(sign(cw)[0], []))
    leaves = json.loads(LEAVES.read_text())
    rows, nc, a, b = [], 0, 0, 0
    for lf in leaves:
        w = obj_words(objs / Path(lf["file"]).with_suffix(".o"), lf["name"])
        if w is None:
            nc += 1
            continue
        s, n = sign(w)
        me = {"file": lf["file"], "name": lf["name"], "insns": len(n)}
        ex = cl.get(s, [])
        if ex:
            a += 1
            rows += [{"mmx4": me, "fleet": mem(m), "tier": "exact", "dist": 0} for m in ex]
            continue
        pn, got = prof(n), []
        for rs, rw, rp, ms in reps:
            v, d, _ = near(n, rw, pn, rp)
            if v == "near":
                got.append({"mmx4": me, "fleet": mem(ms[0]), "tier": "near", "dist": d, "members": len(ms)})
        b += bool(got)
        rows += sorted(got, key=lambda r: (r["dist"], tuple(r["fleet"].values())))
    (objs / "hits.jsonl").write_text("".join(json.dumps(r) + "\n" for r in rows))
    m = len(leaves)
    print(f"sig: foreign {m - nc} of {m} mmx4 leaves signed [{tri}]" + (f", {nc} not compiled" if nc else ""))
    print(f"sig: L8 exact {a} hits, near {b} [{tri}]")
    if not hit:
        print(f"sig: control FAIL -- {CONTROL[1]} did not hit {CONTROL[2]} {CONTROL[3]} exactly")
        return 1
    print(f"sig: control OK -- {CONTROL[1]} hits {CONTROL[2]} {CONTROL[3]} exactly")
    return 0


def selftest():
    fx = json.loads(FIXTURE.read_text())["functions"]
    for f in fx:
        f["words"] = tuple(int(w, 16) for w in f["words"])
    rc, lines, rows = band(fx, group(fx), 2000, SEED, procs=False)
    for x in lines:
        print(x)
    pairs = {(r["a"]["name"], r["b"]["name"]): r["tier"] for r in rows}
    ok = rc == 0
    for (a, b), want in ((("reloc_a", "reloc_b"), "exact"), (("sub_a", "sub_b"), "near"),
                         (("look_a", "look_b"), None)):
        got = pairs.get((a, b))
        print(f"selftest: {a}/{b} {got} (want {want})")
        ok &= got == want
    by = {f["name"]: f for f in fx}
    la, lb = (dup_key(by[n]["words"]) for n in ("look_a", "look_b"))
    mx = max(len(la), len(lb))
    passes = lower_bound(prof(la), prof(lb)) <= cutoff(mx)
    t = lev(la, lb)
    print(f"selftest: lookalike passes prefilter {passes}, true dist {t} of {mx} (ratio {t / mx:.2f})")
    ok &= passes and TD * t >= TN * mx
    # banded vs bit-parallel on random sequences
    rng = random.Random(SEED)
    for _ in range(300):
        a = [rng.randrange(4) for _ in range(rng.randrange(0, 30))]
        b = [rng.randrange(4) for _ in range(rng.randrange(0, 30))]
        t, r = lev(a, b), banded(a, b, max(len(a), len(b)))
        ok &= r is not None and r[0] == t
    print("sig: selftest OK" if ok else "sig: selftest FAIL")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog=__doc__.split("\n\n", 1)[1],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", nargs="?", choices=["band", "build-foreign", "foreign"])
    ap.add_argument("--triple", choices=sorted(TRIPLES), help="build-foreign: mmx4's triple or X5's pin")
    ap.add_argument("--objs", help="foreign: .run/sig/mmx4/<triple>")
    ap.add_argument("--sample", type=int, default=0, help="run band on a deterministic N-function subset")
    ap.add_argument("--pairs", type=int, default=100000, help="random pairs for base rate and control (>= 100000)")
    ap.add_argument("--seed", type=int, default=SEED)
    ap.add_argument("--selftest", action="store_true", help="synthetic reloc / substitution / lookalike fixtures")
    a = ap.parse_args()
    if a.selftest:
        return selftest()
    if a.cmd is None:
        print("sig: refused -- no command (band | build-foreign | foreign)")
        return 2
    if a.cmd == "build-foreign":
        return build_foreign(a.triple) if a.triple else (print("sig: refused -- --triple required") or 2)
    if a.cmd == "foreign":
        return foreign(a.objs) if a.objs else (print("sig: refused -- --objs required") or 2)
    return run_band(a.sample, a.pairs, a.seed)


if __name__ == "__main__":
    sys.exit(main())
