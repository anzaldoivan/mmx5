/* Shared body (DK-5), from the banked draft of func_800EF714_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

extern Ent43AC D_800F43AC_ovl02[];
extern void DEDUP_CALLEE(Obj800EF714*, s32);

void DEDUP_NAME(Obj800EF714* o) {
    s32 v;

    v = o->unk24;
    o->unk20 = 0;
    o->unk28 = 0;
    o->unk80 = v;
    if (v > 0) {
        if (o->unk7E -
                ((Ent43AC*)((u8*)D_800F43AC_ovl02 + o->unk2 * 12))->unk8 >=
            o->unkE) {
            o->unk24 = -v;
            o->unk8A = 0;
            o->unk8B = 2;
            DEDUP_CALLEE(o, 2);
        }
    } else {
        if (o->unkE >=
            o->unk7E +
                ((Ent43AC*)((u8*)D_800F43AC_ovl02 + o->unk2 * 12))->unk8) {
            o->unk24 = -v;
            o->unk8A = 0;
            o->unk8B = 1;
            DEDUP_CALLEE(o, 1);
        }
    }
    if (o->unk24 != o->unk80) {
        o->unk84 = 0x3C;
        DEDUP_CALLEE(o, 1);
    }
}
