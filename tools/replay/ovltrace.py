#!/usr/bin/env python3
"""ovltrace.py -- one PCSX-Redux run of ovltrace.lua (T3.1 phase 2.4): Ovl_Load calls + reads of listed site words.

  ovltrace.py --name N --sites F (--pad P | --stages S[.U][:B@D][>V@K][#V@K][!B][+S/M][*K.J.T@D~F[:ST]][^F[r]:PK],...) [--frames K] [--hold BUTTON] [--timeout SEC]

--sites F: text file; every `site=<hex>` token of a line not containing `sub=asm` gets a 4-byte Read breakpoint.
--stages: `,`-separated jobs, each a stage poke S.U (decimal stage/sub) plus optional ops (full text: ovltrace.lua header):
  :B@D StageC byte B D frames after the poke; >V@K natural sub change; #V@K forced sub change (mode 8); !B forced StageB;
  +S/M ovl18 spawn route; *K.J.T@D~F[:ST] forced call of type T in dispatcher pool J after overlay K loads at 800FA000;
  ^F[r]:PK forced byte poke F frames after the stage poke, PK = `;`-separated hex items `A=V` (address A) or
  `A.S.N+O=V` (offset O of the first free slot, byte 0 == 0, of pool A, stride S, N slots); `r` re-pokes every frame.
  rd lines of `*` and `^` jobs carry forced=1; `^` jobs log one `fpoke` line (slot, mode, stage/sub).

--pad: replay.lua drives the pad (fresh memcards, as replay.py). --stages: poke jobs from one boot (ovltrace.lua header).
ST (natural spawn state, `;`-separated hex): O=V[.W] write, PO parent ptr at +O, CO[.W] copy parent +O.
Log: <--out, default .run/t3_1>/<N>.log (the `redux:` lines); prints load/read/pause counts. Outputs only under .run/ (G12).
"""
import argparse, os, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / '.run/t3_1'


def main():
    a = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    a.add_argument('--name', required=True)
    a.add_argument('--sites', required=True)
    g = a.add_mutually_exclusive_group(required=True)
    g.add_argument('--pad')
    g.add_argument('--stages')
    a.add_argument('--frames', type=int, default=3000)
    a.add_argument('--timeout', type=int, default=3000)
    a.add_argument('--out', default=str(OUT), help='log dir (under .run/)')
    a.add_argument('--hold', help='poke mode: hold this pad button after the poke, tap CROSS only')
    a = a.parse_args()
    env = dict(os.environ, REDUX_SITES=str(Path(a.sites).resolve()), REDUX_FRAMES=str(a.frames),
               REDUX_TIMEOUT=str(a.timeout), PY=sys.executable)
    args = ['-interpreter', '-debugger']
    if a.pad:
        env['REDUX_PAD'] = str(Path(a.pad).resolve())
        cards = ROOT / '.run/replay/cards'
        shutil.rmtree(cards, ignore_errors=True)
        cards.mkdir(parents=True)
        args += ['-memcard1', str(cards / 'card1.mcd'), '-memcard2', str(cards / 'card1.mcd')]
    else:
        env['REDUX_STAGES'] = a.stages
        if a.hold:
            env['REDUX_HOLD'] = a.hold
    p = subprocess.run(['bash', str(ROOT / 'tools/redux/run.sh'), str(ROOT / 'tools/replay/ovltrace.lua'), *args],
                       env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    lines = [l for l in (ROOT / '.run/redux/ovltrace.log').read_text(errors='replace').splitlines()
             if l.startswith('redux: ')]
    (out / f'{a.name}.log').write_text(''.join(l + '\n' for l in lines))
    n = {k: sum(l.startswith(f'redux: {k} ') for l in lines) for k in ('load', 'rd', 'poke', 'fpoke', 'pause', 'fspawn', 'fstate', 'fcall', 'done')}
    print(f'ovltrace: {a.name} rc={p.returncode} ' + ' '.join(f'{k}={v}' for k, v in n.items()))
    return p.returncode


if __name__ == '__main__':
    sys.exit(main())
