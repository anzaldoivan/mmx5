/* Shared body (DK-5), from the banked draft of func_800FC0B8_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FF748_ovl06[])(ObjFAF30*, ObjFAF30*);

static inline void inl_800FC108(ObjFAF30* a, ObjFAF30* p) {
    if (p->unk9A != 0) {
        if (p->unk9A > 0) {
            a->unk3 = 1;
            a->unk54 = 10;
            a->unk56 = 8;
            a->unk58 = (5 - a->unk2) * 2;
            a->unk8 = p->unk8;
            a->unkC = p->unkC;
            a->unk5 = 1;
            a->pad6[0] = 0;
        } else {
            p->unk9A = 0;
        }
    }
}

void DEDUP_NAME(ObjFAF30* a) {
    ObjFAF30* p = a->unk50;

    a->unk47 = p->unk47;
    a->unk15 = p->unk15;
    a->unk38 = p->unk38;
    a->unk3C = p->unk3C;
    a->unk18 = a->unk8;
    a->unk1C = a->unkC;
    if (a->unk5 == 0) {
        inl_800FC108(a, p);
    } else if (p->unk9A == 0) {
        a->unk3 = 0;
        a->unk5 = 0;
    } else {
        D_800FF748_ovl06[(s8)a->pad6[0]](a, p);
    }
}
