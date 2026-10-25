"""Bind the T3.1 trace's cross-overlay site words: one class per owners.txt site row (T3.1.1).

usage: ovlbind.py <owners.txt>   (reads build/rockx5/ROCK_X5.BIN.elf, build/slus/SLUS_013.34.elf)
Prints per-class counts; when every row is classed, rewrites config/reloc_addrs.rockx5.txt (drops lines at the
site roms, appends one reloc per bound site) and appends allowlisted words to config/shift/not_pointers.txt.
Unclassed rows are printed and nothing is written (exit 1): never guessed. Class `8 held` rows (ovl18 dispatch table,
owner unknown) get no reloc and no allowlist line.
"""
import re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "shift"))
import scan  # noqa: E402  (ELF parse)

ROCK = "build/rockx5/ROCK_X5.BIN.elf"
EXE = "build/slus/SLUS_013.34.elf"
RELOC = Path("config/reloc_addrs.rockx5.txt")
ALLOW = Path("config/shift/not_pointers.txt")
TAG = "(T3.1 trace, G74)"
HEAD = "// T3.1.1 ovlbind.py (logs/T3.1.1.c1.md): trace-bound site words -> owner overlay symbol"
OVL16_TAB = (0x800EF2E4, 0x800EF32C)  # ovl16 obj+0x1D dispatch table, entry i -> g_OvlIdxStageC[i]
OVL18_TAB = (0x800F6CF4, 0x800F7238)  # D_800F6CF4_ovl18 object-type dispatch table: owner unknown -> held (no line)
ALLOW_EV = {"tgt_region_never_resident_with_X": "target region never resident while X resident",
            "X_loaded_only_over_a_remnant": "X only loaded over a remnant, target outside X",
            "site_read,_val_not_covered": "site read, value never covered by a resident overlay"}
ROW = re.compile(r"^(data|hilo|wrong) (ovl\d\d) site=(\w+) rom=(\w+) tgt=(\w+) rule=\S+ pick=\S+ owner=(\S+) "
                 r"tier=(\w+) ev=(\S+)$")


def rows(path):
    lines = Path(path).read_text().splitlines()
    sets = next(l for l in lines if l.startswith("observed co-resident sets"))
    obs = [{int(n.rstrip("*")) for n in s.split(",")} for s in re.findall(r"\{([^}]*)\}", sets)]
    out = []
    for l in lines[218:]:
        m = ROW.match(l)
        assert m, l
        k, x, site, rom, tgt, owner, tier, ev = m.groups()
        out.append(dict(kind=k, x=x, site=int(site, 16), rom=int(rom, 16), tgt=int(tgt, 16), owner=owner,
                        tier=tier, ev=ev))
    return out, obs


def stage_c():
    e = scan.parse(Path(EXE).read_bytes())
    va = next(v for n, v, *_ in e["syms"] if n == "g_OvlIdxStageC")
    s = next(s for s in e["secs"] if s["bytes"] and 0 <= va - s["addr"] < len(s["bytes"]))
    o = va - s["addr"]
    return list(s["bytes"][o:o + 19])


def symtab():
    """ovlNN -> (lo, hi, [(value, size, name)], {RODATA_START/END: value}) of the segment's own func_/D_/jtbl_
    symbols (no .NON_MATCHING) and its linker rodata bounds."""
    e = scan.parse(Path(ROCK).read_bytes())
    out = {}
    for i, s in enumerate(e["secs"]):
        if re.fullmatch(r"\.ovl\d\d", s["name"]):
            o = s["name"][1:]
            syms = sorted((v, sz, n) for n, v, sz, t, x in e["syms"]
                          if x == i and n.startswith(("func_", "D_", "jtbl_")) and "." not in n)
            rod = {n[len(o) + 1:]: v for n, v, sz, t, x in e["syms"]
                   if x == i and n in (f"{o}_RODATA_START", f"{o}_RODATA_END")}
            out[o] = (s["addr"], s["addr"] + s["size"], syms, rod)
    return out


def resolve(tab, o, tgt):
    """-> (name, addend) of o's symbol at/containing tgt, or None."""
    lo, hi, syms, rod = tab[o]
    if not lo <= tgt < hi:
        return None
    exact = sorted((not n.startswith("func_"), n) for v, sz, n in syms if v == tgt)
    if exact:
        return exact[0][1], 0
    box = [(v, n) for v, sz, n in syms if v < tgt < v + sz]
    if box:
        return max(box)[1], tgt - max(box)[0]
    # T3.1.1.c2: 4 own targets sit in a C object's .rodata (local jtbl, no global label; no rodatabin to split)
    if rod.get("RODATA_START", hi) <= tgt < rod.get("RODATA_END", lo):
        return f"{o}_RODATA_START", tgt - rod["RODATA_START"]
    return None


def classify(r, obs, sc):
    x, ev, tier, owner = r["x"], r["ev"], r["tier"], r["owner"]
    xn = int(x[3:])
    if r["kind"] == "hilo":
        return "6 load-dest", None
    if x == "ovl16" and OVL16_TAB[0] <= r["site"] <= OVL16_TAB[1]:
        o = sc[(r["site"] - OVL16_TAB[0]) // 4]
        cs = {int(n[3:]) for n in ev.split(":_")[1].split(",")} if ev.startswith("co-resident_at_tgt") else set()
        ok = (owner == f"ovl{o:02}" if tier == "read" else o in cs) and any({xn, o} <= s for s in obs)
        if ok:
            return "4 table", f"ovl{o:02}"
    if tier in ("coresident", "read") and owner == x:
        return "1 own", x
    if tier == "coresident" and re.fullmatch(r"ovl\d\d", owner):
        return "2 coresident-other", owner
    if tier == "read" and re.fullmatch(r"ovl\d\d", owner):
        return "3 read-other", owner
    if tier == "unreached" and ev.startswith("co-resident_at_tgt") and x in ev.split(":_")[1].split(","):
        return "5 own-in-set", x
    if tier == "unreached" and ev.split(":")[0] in ALLOW_EV:
        return "7 allow", None
    if x == "ovl18" and OVL18_TAB[0] <= r["site"] < OVL18_TAB[1]:
        return "8 held", None
    return None, None


def main():
    rs, obs = rows(sys.argv[1])
    assert len(rs) == 801, len(rs)
    sc, tab = stage_c(), symtab()
    assert sc == list(range(40, 59)), sc  # g_OvlIdxStageC[i] == 40 + i
    counts, bad, rel, allow = {}, [], [], []
    for r in rs:
        c, o = classify(r, obs, sc)
        if c in ("1 own", "2 coresident-other", "3 read-other", "4 table", "5 own-in-set"):
            hit = resolve(tab, o, r["tgt"])
            if hit is None:
                bad.append(f"nosym {o} " + fmt(r))
                continue
            n, a = hit
            rel.append(f"rom:0x{r['rom']:X} reloc:MIPS_32 symbol:{n}" + (f" addend:0x{a:X}" if a else "")
                       + f" // {r['x']} {r['site']:08X} -> {r['tgt']:08X} c{c[0]} {r['tier']}")
        elif c == "7 allow":
            why = r["ev"].split(":")[0]
            if why == "X_loaded_only_over_a_remnant":
                lo, hi, *_ = tab[r["x"]]
                assert not lo <= r["tgt"] < hi, fmt(r)
            allow.append(f"rockx5 {r['site']:08X} {r['tgt']:08X} -- {r['x']}: {ALLOW_EV[why]} "
                         f"(ev={r['ev']}) {TAG}")
        elif c is None:
            bad.append("unclassed " + fmt(r))
            continue
        counts[c] = counts.get(c, 0) + 1
    for c in sorted(counts):
        print(f"class {c}: {counts[c]}")
    print(f"classed {sum(counts.values())} of {len(rs)}; reloc {len(rel)}, allow {len(allow)}, unclassed {len(bad)}")
    if bad:
        print("\n".join(bad))
        return 1
    assert sum(counts.values()) == 801
    drop = {r["rom"] for r in rs if r["kind"] != "hilo"}
    keep = [l for l in RELOC.read_text().splitlines() if l != HEAD and not
            (l.startswith("rom:") and int(l.split()[0][4:], 16) in drop)]
    print(f"reloc_addrs: kept {sum(l.startswith('rom:') for l in keep)} other lines, appended {len(rel)}")
    RELOC.write_text("\n".join(keep + [HEAD] + rel) + "\n")
    old = [l for l in ALLOW.read_text().splitlines() if TAG not in l]
    ALLOW.write_text("\n".join(old + allow) + "\n")
    return 0


def fmt(r):
    return f"{r['x']} site={r['site']:08X} tgt={r['tgt']:08X} owner={r['owner']} tier={r['tier']} ev={r['ev']}"


if __name__ == "__main__":
    sys.exit(main())
