/* Shared body (DK-5), from the banked draft of func_800F3DD4_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s16 D_8009A0AA;
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern void func_800171E8(Obj3DD4*, s32);
extern void func_80017248(Obj3DD4*);
extern void func_8002DED4(Obj3DD4*);

void DEDUP_NAME(Obj3DD4* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE <= D_800FA244_ovl03) {
        o->unkE = D_800FA244_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        func_800171E8(o, 5);
        o->unk7C = 0;
        o->unk7E = 0;
        o->unk6++;
    }
    func_80017248(o);
    func_8002DED4(o);
}
