/* Shared body (DK-5), from the banked draft of func_800EF5D8_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

extern Ent43AC D_800F43AC_ovl02[];
extern void DEDUP_CALLEE(Obj800EF5D8*, s32);

void DEDUP_NAME(Obj800EF5D8* o) {
    s32 v = o->unk20;

    o->unk24 = 0;
    o->unk2C = 0;
    o->unk80 = v;
    if (v > 0) {
        if (o->unkA >= o->unk7C + (D_800F43AC_ovl02 + o->unk2)->unk8) {
            o->unk20 = -v;
            o->unk8A = 0;
            o->unk8B = 3;
            DEDUP_CALLEE(o, 3);
        }
    } else {
        if (o->unk7C - (D_800F43AC_ovl02 + o->unk2)->unk8 >= o->unkA) {
            o->unk20 = -v;
            o->unk8A = 0;
            o->unk8B = 4;
            DEDUP_CALLEE(o, 4);
        }
    }
    if (o->unk20 != o->unk80 || o->unk7) {
        if (o->unk7) {
            o->unk20 = 0xFFFF0000;
            o->unk7 = 0;
            o->unk8A = 0;
            o->unk8B = 4;
            o->unk7C += 0x50;
        }
        o->unk84 = 0x3C;
        DEDUP_CALLEE(o, 1);
    }
}
