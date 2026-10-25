"""Live proof of the SLUS_013.34 load address and the first ROCK_X5.BIN overlay load (T5).

Drives tools/redux/run.sh with prove_exe.lua (2 boots, different frame counts) and prove_overlay.lua, compares the
RAM hashes with file-slice hashes, prints t4-agrees/t4-differs vs docs/oracle/loadmap.json (never edits it), and
regenerates the `- datapoint` lines under `## Datapoints` in docs/memory-map.md. Exit 1 on any mismatch.
Env: PROVE_T_ADDR overrides the claimed exe load address (negative control). Hashes only, never bytes (G12).
"""
import datetime
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import psexe  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / "extracted/retail/SLUS_013.34"
BIN = ROOT / "extracted/retail/ROCK_X5.BIN"
OUT = ROOT / ".run/redux"
MAP = ROOT / "docs/memory-map.md"
WINDOWS = (0x80015DDC, 0x8005894C, 0x80067F98)  # Ovl_ReadToc, pc0, deep .text; never 80010000 (a runtime variable)
BOOTS = (300, 600)  # frames per exe boot
LEN = 256


def h8(v):
    return f"{v:08X}"


def sha(b):
    return hashlib.sha1(b).hexdigest()


def redux(script, log_name, env, *args, timeout=200):
    """Run one boot; copy its log to a distinct name so later boots do not overwrite it."""
    e = dict(os.environ, REDUX_TIMEOUT=str(timeout), PY=sys.executable, **env)
    r = subprocess.run(["bash", str(ROOT / "tools/redux/run.sh"), str(ROOT / "tools/redux" / script), *args],
                       env=e, capture_output=True, text=True)
    log = OUT / log_name
    shutil.copyfile(OUT / (Path(script).stem + ".log"), log)
    lines = [l for l in log.read_text(errors="replace").splitlines() if l.startswith("redux: ")]
    return r.returncode, lines, log.relative_to(ROOT).as_posix()


def kv(line):
    return dict(re.findall(r"(\S+?)=(\S+)", line))


def ovl3839(frames=12000, spawn=600, state6=300):
    """Spawn-poke route to ovl38/39 (T4). Prints hit/after/poke lines; never writes the oracle (loadmap.py LIVE does).
    Exit 0 iff an idx 38|39 hit has dest 800FA000 and ra in ovl18 (38: 800F6B38, 39: 800F6C38); then regenerates the
    `- ovl38:`/`- ovl39:` lines of docs/memory-map.md from the hits."""
    rc, lines, log = redux("prove_ovl3839.lua", "prove_ovl3839.spawn.log",
                           {"REDUX_STAGE": "12", "REDUX_POKE_HIT": "4", "REDUX_FRAMES": str(frames),
                            "REDUX_SPAWN_DELAY": str(spawn), "REDUX_STATE6_DELAY": str(state6)},
                           "-interpreter", "-debugger", timeout=frames // 30 + 60)
    ok, proven = False, {}
    for l in lines:
        if l.startswith(("redux: hit", "redux: ovl after", "redux: poke", "redux: pause", "redux: done")):
            print(l)
        d = kv(l)
        if l.startswith("redux: hit Ovl_Load ") and d["idx"] in ("38", "39") and int(d["dest"], 16) == 0x800FA000 \
                and int(d["ra"], 16) == {"38": 0x800F6B38, "39": 0x800F6C38}[d["idx"]]:
            ok = True
            proven.setdefault(d["idx"], f"- ovl{d['idx']}: dest {d['dest']} proven live (phase 2.2 T4): Ovl_Load(0x{int(d['idx']):X}) "
                                        f"a1={d['dest']} ra={d['ra']} (ovl18), spawn-poke route `PY tools/loadmap/prove.py ovl3839`; "
                                        f"{datetime.date.today().isoformat()} {log}")
    if ok:
        text = MAP.read_text().splitlines()
        MAP.write_text("\n".join(proven.get(l[5:7], l) if l.startswith(("- ovl38:", "- ovl39:")) else l
                                 for l in text) + "\n")
    print(f"prove ovl3839: {'OK' if ok else 'FAIL'} rc={rc} log={log}")
    return 0 if ok else 1


def main():
    if sys.argv[1:] == ["ovl3839"]:
        return ovl3839()
    claimed = json.loads((ROOT / "docs/oracle/loadmap.json").read_text())
    hdr = psexe.parse(EXE)
    t_addr = int(os.environ.get("PROVE_T_ADDR", "0"), 16) or hdr["t_addr"]
    exe = EXE.read_bytes()
    today = datetime.date.today().isoformat()
    fails, points, report = [], [], []

    # exe: one datapoint per (boot, window)
    live_base = None
    for n, frames in enumerate(BOOTS, 1):
        rc, lines, log = redux("prove_exe.lua", f"prove_exe.boot{n}.log",
                               {"REDUX_FRAMES": str(frames), "REDUX_WINDOWS": ",".join(map(hex, WINDOWS))})
        if rc:
            fails.append(f"exe boot{n}: run.sh rc={rc} ({log})")
            continue
        ram = {(int(d["addr"], 16), int(d["delta"])): d["sha1"] for d in map(kv, lines) if "delta" in d}
        for l in lines:
            if l.startswith("redux: base "):
                live_base = l.split("=")[1].strip()
        for a in WINDOWS:
            off = 0x800 + a - t_addr
            f = sha(exe[off:off + LEN])
            got = ram.get((a, 0))
            ok = got == f and f not in (ram.get((a, -4)), ram.get((a, 4)))
            print(f"exe boot{n} frames={frames} {h8(a)} file=SLUS_013.34:0x{off:X}+0x{LEN:X} sha1={f} ram={got} "
                  f"{'ok' if ok else 'MISMATCH'}")
            if not ok:
                fails.append(f"exe boot{n} {h8(a)}")
            points.append(f"- datapoint exe {h8(a)} window SLUS_013.34:0x{off:X}+0x{LEN:X} sha1={f} ram={got} "
                          f"{today} {log}")
    exe_ok = not any(x.startswith("exe") for x in fails)
    report.append(("exe-t_addr", claimed["exe"]["t_addr"], h8(t_addr) if exe_ok else "mismatch"))

    # overlay: before/after of the first Ovl_Load
    rc, lines, log = redux("prove_overlay.lua", "prove_overlay.boot1.log", {"REDUX_FRAMES": "5000"},
                           "-interpreter", "-debugger", timeout=240)
    for l in lines:
        if l.startswith("redux: hit"):
            print(l[7:])
    before = next((kv(l) for l in lines if l.startswith("redux: ovl before")), None)
    after = next((kv(l) for l in lines if l.startswith("redux: ovl after")), None)
    hit = next((kv(l) for l in lines if l.startswith("redux: hit Ovl_Load ")), None)
    if rc or not (before and after and hit):
        fails.append(f"ovl: run.sh rc={rc}, no first hit/after ({log})")
    else:
        idx, dest, size = int(before["idx"]), before["dest"], int(before["size"], 16)
        toc_sec, toc_size = struct.unpack_from("<II", BIN.read_bytes(), 8 * idx)
        bo = toc_sec * 0x800
        f = sha(BIN.read_bytes()[bo:bo + toc_size])
        ok = before["sha1"] != after["sha1"] and after["sha1"] == f and size == toc_size
        print(f"ovl{idx} dest={dest} file=ROCK_X5.BIN:0x{bo:X}+0x{toc_size:X} sha1={f} before={before['sha1']} "
              f"after={after['sha1']} after_frame={after['frame']} {'ok' if ok else 'MISMATCH'}")
        if not ok:
            fails.append(f"ovl{idx} before/after")
        points.append(f"- datapoint ovl{idx} {dest} before-after ROCK_X5.BIN:0x{bo:X}+0x{toc_size:X} sha1={f} "
                      f"ram={after['sha1']} {today} {log}")
        o = claimed["overlays"][idx]
        report += [(f"ovl{idx}-dest", o["dest"] or "null", dest),
                   (f"ovl{idx}-size", f"{o['size']:X}", f"{size:X}"),
                   (f"ovl{idx}-toc_sec", f"{o['bin_offset'] // 0x800:X}", hit["toc_sec"]),
                   ("base-*80010000", "800EE970", hit["base"])]
        lba = next(json.loads(l)["lba"] for l in (ROOT / "extracted/retail/manifest.jsonl").read_text().splitlines()
                   if '"ROCK_X5.BIN"' in l)
        if int(hit["toc_sec"], 16) == lba + toc_sec:
            print(f"note: live TOC sector = ROCK_X5.BIN disc lba {lba:X} + file TOC sector {toc_sec:X}")
    if live_base:
        report.append(("base-*80010000-exe-boot", "800EE970", live_base))
    for i in (38, 39):
        hits = [kv(l)["dest"] for l in lines if l.startswith("redux: hit Ovl_Load ") and kv(l)["idx"] == str(i)]
        report.append((f"ovl{i}-dest", claimed["overlays"][i]["dest"] or "null", ",".join(sorted(set(hits))) or "no-hit"))
    for what, c, live in report:
        agree = c == live or (live == "no-hit")
        print(f"{'t4-agrees' if agree else 't4-differs'} {what} claimed={c} live={live}")

    if fails:
        print("prove: FAIL", "; ".join(fails))
        return 1
    text = MAP.read_text()
    head, sep, tail = text.partition("## Datapoints\n")
    assert sep, "docs/memory-map.md: no ## Datapoints section"
    kept = [l for l in tail.splitlines() if not l.startswith("- datapoint ")]
    while kept and not kept[-1].strip():
        kept.pop()
    MAP.write_text(head + sep + "\n".join(kept + points) + "\n")
    print(f"prove: OK {len(points)} datapoints -> {MAP.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
