#include "types.h"

extern Obj66A0 D_8009A0A0;
extern s32 func_800317B8(Obj66A0*);
extern s32 func_80031DD0(Obj66A0*);
extern s32 func_8004FD24(Obj66A0*);
extern void func_8002D9EC(Obj66A0*, s32, s32);
extern void func_80017248(Obj66A0*);
extern void func_8002DED4(Obj66A0*);

void func_800F66A0_ovl03(Obj66A0* o) {
    s32 vx;
    s32 r;
    s32 vy;
    s32 d;

    vx = 0x14000;
    vy = 0x8000;
    r = func_800317B8(o);
    o->unk42 &= 0x7FFF;
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        o->unk4++;
        func_8002D9EC(o, 0x16, 0x16);
        return;
    }
    switch (o->unk5) {
    case 0:
        if (!(o->unk7C & 3)) {
            o->unk24 = -o->unk24;
        }
        if (++o->unk7C == 0x28) {
            if (D_8009A0A0.unkA > o->unkA) {
                o->unk15 = 0x40;
            } else {
                o->unk15 = 0;
            }
            if (o->unkA > D_8009A0A0.unkA) {
                o->unk20 = -vx;
            } else {
                o->unk20 = 0;
            }
            if (o->unkA == D_8009A0A0.unkA) {
                o->unk20 = 0;
            }
            if (D_8009A0A0.unkE < o->unkE) {
                o->unk24 = vy;
            } else {
                o->unk24 = -vy;
            }
            o->unk7C = 0;
            o->unk5++;
        }
        break;
    case 1:
        if (++o->unk7C == 0xD2 || r != 0) {
            o->unk24 = 0x20000;
            o->unk20 = 0;
            o->unk7C = 0;
            o->unk5++;
            break;
        }
        if (!(o->unk7C & 3)) {
            if (D_8009A0A0.unkA > o->unkA) {
                o->unk15 = 0x40;
            } else {
                o->unk15 = 0;
            }
            if (o->unkA > D_8009A0A0.unkA) {
                o->unk20 = -vx;
            } else {
                o->unk20 = vx;
            }
            if (D_8009A0A0.unkE < o->unkE) {
                o->unk24 = vy;
            } else {
                o->unk24 = -vy;
            }
        }
        d = o->unkA - D_8009A0A0.unkA;
        if ((d >= 0) ? (d < 2) : (D_8009A0A0.unkA - o->unkA < 2)) {
            o->unk20 = 0;
        }
        if (o->unkE == D_8009A0A0.unkE) {
            o->unk24 = 0;
        }
        break;
    case 2:
        if (++o->unk7C == 0x78) {
            o->unk4 = 2;
        }
        break;
    }
    if (o->unk80->busy == 2) {
        func_8004FD24(o);
        o->unk4 = 2;
    }
    if (o->unk80->arg == 10) {
        o->unk4 = 2;
    }
    func_8002D9EC(o, 0x10, 0x10);
    func_80017248(o);
    func_8002DED4(o);
}
