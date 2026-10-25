#!/usr/bin/env python3
"""replay.py -- run a .pad script through PCSX-Redux N times and compare checkpoints (T1 phase 2.2; README.md).

  replay.py run [--cue C] [--plant A:W@F] --pad P --runs N --out DIR   one serial run per DIR/run<i>/
                                                      (checkpoints.jsonl, stdout.txt, redux.log, PNGs)
  replay.py compare A B                                 `replay: <k> checkpoints, <d> divergences`; exit 1 if d > 0
  replay.py compare ORIG PATCHED --from CP              patch verdict, PATCHED/run1..runN (mk/replay.mk replay-patch);
                                                      exit 0 only on PASS
  replay.py check                                       original x3, rebuilt x1, plant x1 (plants.txt) on intro.pad
  replay.py --selftest                                  parser + compare + plant verdict on synthetic records

Memcards: both slots on a fresh repo-local card, .run/replay/cards/card1.mcd, deleted before every run (README.md).
"""
import argparse, json, os, re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CARDS = ROOT / '.run/replay/cards'
PLANTS = ROOT / 'tools/replay/plants.txt'
CP = re.compile(r'redux: cp (\S+) frame=(\d+) stage/sub=(\d+)/(\d+) vram_sha1=([0-9a-f]{40})\s*$')


def parse(lines):
    return [{'name': m[1], 'frame': int(m[2]), 'stage': int(m[3]), 'sub': int(m[4]), 'vram_sha1': m[5]}
            for m in map(CP.search, lines) if m]  # search: tolerates a glued preceding line


def end_frame(pad):
    ends = [int(l.split()[0]) for l in Path(pad).read_text().splitlines() if re.match(r'^\s*\d+\s+end\b', l)]
    if not ends:
        sys.exit(f'replay: {pad} has no end line')
    return ends[0]


def run(a):
    pad, out = Path(a.pad).resolve(), Path(a.out).resolve()
    env = dict(os.environ, REDUX_PAD=str(pad), REDUX_TIMEOUT=str(end_frame(pad) // 30 + 60))
    if a.cue:
        env['REDUX_CUE'] = str(Path(a.cue).resolve())
    if a.plant:
        env['REDUX_PLANT'] = a.plant
    bad = 0
    for i in range(1, a.runs + 1):
        d = out / f'run{i}'
        shutil.rmtree(d, ignore_errors=True)
        d.mkdir(parents=True)
        shutil.rmtree(CARDS, ignore_errors=True)  # fresh empty card per run; Redux creates it
        CARDS.mkdir(parents=True)
        card = str(CARDS / 'card1.mcd')
        # Redux 298 sets Mcd2 from -memcard1's value too; both flags given so neither slot falls back to ~/.config
        p = subprocess.run(['bash', str(ROOT / 'tools/redux/run.sh'), str(ROOT / 'tools/replay/replay.lua'),
                            '-memcard1', card, '-memcard2', card],
                           env=dict(env, REDUX_OUT=str(d)), capture_output=True, text=True)
        (d / 'stdout.txt').write_text(p.stdout)
        shutil.copy(ROOT / '.run/redux/replay.log', d / 'redux.log')
        cps = parse(p.stdout.splitlines())
        (d / 'checkpoints.jsonl').write_text(''.join(json.dumps(c) + '\n' for c in cps))
        ended = any(l.startswith('redux: end ') for l in p.stdout.splitlines())
        bad += p.returncode != 0 or not ended
        print(f'replay: run{i} rc={p.returncode} {len(cps)} checkpoints end={"yes" if ended else "no"}')
    return 1 if bad else 0


def load(d):
    return [json.loads(l) for l in (Path(d) / 'checkpoints.jsonl').read_text().splitlines() if l.strip()]


def diff(a, b):
    """-> (k, divergent names in A's order then B-only); a checkpoint diverges if missing or any field differs."""
    ia, ib = {c['name']: c for c in a}, {c['name']: c for c in b}
    names = list(ia) + [n for n in ib if n not in ia]
    return len(names), [n for n in names if ia.get(n) != ib.get(n)]


def compare(a):
    if a.from_cp:
        return compare_patch(a)
    k, dv = diff(load(a.a), load(a.b))
    print(f'replay: {k} checkpoints, {len(dv)} divergences')
    if dv:
        print(f'replay: first divergence {dv[0]}')
    return 1 if dv or not k else 0


def patch_rule(names, dv, runs_same, at):
    """-> None (pass) or the failed rule; at = index of the declared cp in intro order (names)."""
    if not runs_same:
        return 'patched runs differ'
    if not dv:
        return 'no divergence'
    if min(names.index(n) for n in dv) < at:
        return 'diverges before declared'
    return None


def compare_patch(a):
    """Pass iff the patched runs are identical, diverge from ORIG, never before --from; control: --from moved past
    the first divergence must fail."""
    runs = sorted(Path(a.b).glob('run*/checkpoints.jsonl'), key=lambda p: int(p.parent.name[3:]))
    pr = [load(p.parent) for p in runs]
    label = getattr(a, 'label', 'replay-patch')
    name = Path(a.b).name.removeprefix('patch-').removeprefix('asset-')
    dv = diff(load(a.a), pr[0])[1] if pr else []
    names = [c['name'] for c in load(a.a)]  # intro order: ORIG's, then patched-only cps
    names += [n for n in dv if n not in names]
    same = bool(pr) and all(p == pr[0] for p in pr)
    first = dv[0] if dv else 'none'
    if a.from_cp not in names:
        rule = f'declared cp {a.from_cp} unknown'
    else:
        rule = patch_rule(names, dv, same, names.index(a.from_cp))
        if rule is None:  # control: same evaluation, declared one cp after the first divergence
            if patch_rule(names, dv, same, names.index(first) + 1) is None:
                rule = 'control not caught'
            else:
                print('replay: control caught')
    print(f'replay: patch {name} {len(dv)} divergences, first {first}, declared {a.from_cp}, '
          f'runs {len(pr)} {"identical" if same else "NOT identical"}: ' + ('PASS' if rule is None else f'FAIL ({rule})'))
    if rule is None:  # PASS implies the control was caught (else rule = 'control not caught')
        print(f'{label}: {name} OK (first divergence {first} >= declared {a.from_cp}, '
              f'{len(pr)} of {len(pr)} deterministic, control caught)')
    return 0 if rule is None else 1


def caught(a, b, declared):
    """-> declared iff the first divergence of b vs a is the declared cp (so every earlier cp is equal), else None."""
    dv = diff(a, b)[1]
    return declared if dv and dv[0] == declared else None


def check(_):
    py, rr = sys.executable, ROOT / '.run/replay'
    cue = ROOT / 'build/disc/mmx5.cue'
    if not cue.exists():
        subprocess.run(['make', 'disc', f'PY={py}'], cwd=ROOT, check=True)
    pad = str(ROOT / 'tools/replay/scripts/intro.pad')
    spec, declared = next(l.split() for l in PLANTS.read_text().splitlines() if l.strip() and not l.startswith('#'))
    ns = argparse.Namespace
    red = run(ns(pad=pad, runs=3, out=rr / 'original', cue=None, plant=None))
    red |= run(ns(pad=pad, runs=1, out=rr / 'rebuilt', cue=str(cue), plant=None))
    run(ns(pad=pad, runs=1, out=rr / 'plant', cue=None, plant=spec))  # rc ignored: a plant may hang the game
    o = [load(rr / 'original' / f'run{i}') for i in (1, 2, 3)]
    k, dv = diff(o[0], o[1])
    dv += diff(o[0], o[2])[1]
    if dv or k < 6:
        red = 1
        print(f'replay: original NOT identical ({k} checkpoints, divergent {sorted(set(dv))})')
    else:
        print(f'replay: original 3 of 3 identical, {k} checkpoints')
    dv = diff(o[0], load(rr / 'rebuilt/run1'))[1]
    print(f'replay: rebuilt {len(dv)} divergences' + (f' (first {dv[0]})' if dv else ''))
    red |= bool(dv)
    pl = load(rr / 'plant/run1')
    if caught(o[0], pl, declared):
        print(f'replay: plant caught at {declared}')
    else:
        red = 1
        dv = diff(o[0], pl)[1]
        print(f'replay: plant NOT caught at {declared} (first divergence {dv[0] if dv else "none"})')
    return 1 if red else 0


def selftest():
    h1, h2 = 'a' * 40, 'b' * 40
    a = parse(['redux: cp boot frame=10 stage/sub=0/0 vram_sha1=' + h1, 'noise',
               'redux: cp title frame=20 stage/sub=14/0 vram_sha1=' + h2, 'redux: end frame=30'])
    assert [c['name'] for c in a] == ['boot', 'title'] and a[1]['stage'] == 14 and a[1]['frame'] == 20
    assert diff(a, a) == (2, [])
    b = [dict(a[0]), dict(a[1], vram_sha1=h1)]
    assert diff(a, b) == (2, ['title'])
    assert diff(a, a[:1]) == (2, ['title'])
    assert diff(a[:1], a) == (2, ['title'])
    g = parse(["Error in event listener: boomredux: cp boot frame=10 stage/sub=0/0 vram_sha1=" + h1])
    assert g == a[:1]
    c = a + [dict(a[1], name='late')]
    assert caught(c, c, 'title') is None
    assert caught(c, b + c[2:], 'title') == 'title'
    assert caught(c, b + c[2:], 'late') is None  # diverges earlier than declared
    assert caught(c, c[:2], 'late') == 'late'  # missing declared cp counts
    assert caught(c, c[:2], 'title') is None
    # compare --from: synthetic jsonl, ORIG c (title, late), PATCHED dirs of run1..runN
    st = ROOT / '.run/replay/selftest'
    shutil.rmtree(st, ignore_errors=True)
    def patched(tag, *runs):
        for i, r in enumerate(runs, 1):
            (st / tag / f'run{i}').mkdir(parents=True)
            (st / tag / f'run{i}' / 'checkpoints.jsonl').write_text(''.join(json.dumps(x) + '\n' for x in r))
        return st / tag
    (st / 'orig').mkdir(parents=True)
    (st / 'orig/checkpoints.jsonl').write_text(''.join(json.dumps(x) + '\n' for x in c))
    late = c[:2] + [dict(c[2], vram_sha1=h1)]
    def verdict(p, cp):
        return compare_patch(argparse.Namespace(a=st / 'orig', b=p, from_cp=cp))
    assert verdict(patched('patch-pass', late, late, late), 'title') == 0
    assert verdict(patched('patch-early', b + c[2:], b + c[2:]), 'late') == 1
    assert verdict(patched('patch-none', c, c), 'title') == 1
    assert verdict(patched('patch-nondet', late, c[:2] + [dict(c[2], vram_sha1='c' * 40)]), 'title') == 1
    shutil.rmtree(st)
    print('replay: selftest OK')
    return 0


def main():
    if sys.argv[1:] == ['--selftest']:
        return selftest()
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    r = sub.add_parser('run')
    r.add_argument('--cue', help='disc cue (default: run.sh default, the retail disc)')
    r.add_argument('--pad', required=True)
    r.add_argument('--runs', type=int, default=1)
    r.add_argument('--out', required=True)
    r.add_argument('--plant', help='REDUX_PLANT <hexaddr>:<hexword>@<frame> (plants.txt)')
    c = sub.add_parser('compare')
    c.add_argument('a')
    c.add_argument('b')
    c.add_argument('--from', dest='from_cp', help='patch verdict: B holds run1..runN; first cp the patch may change')
    c.add_argument('--label', default='replay-patch', help='prefix of the OK line (replay-asset for make replay-asset)')
    sub.add_parser('check')
    a = ap.parse_args()
    return {'run': run, 'compare': compare, 'check': check}[a.cmd](a)


if __name__ == '__main__':
    sys.exit(main())
