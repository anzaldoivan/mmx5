#include "types.h"

extern void (*D_800FE7F8_ovl28[])(ObjFAF30*, ObjFAF30*);

static inline void inl_800FB080(ObjFAF30* a, ObjFAF30* p) {
    if (p->unk9A != 0) {
        if (p->unk9A > 0) {
            a->unk3 = 1;
            a->unk54 = 3;
            a->unk56 = 8;
            a->unk58 = (5 - a->unk2) * 2;
            a->unk8 = p->unk8;
            a->unkC = p->unkC;
            a->unk4 = 1;
            a->unk5 = 0;
        } else {
            p->unk9A = 0;
        }
    }
}

void func_800FAF30_ovl28(ObjFAF30* a) {
    ObjFAF30* p = a->unk50;

    a->unk47 = p->unk47;
    a->unk15 = p->unk15;
    a->unk38 = p->unk38;
    a->unk3C = p->unk3C;
    a->unk18 = a->unk8;
    a->unk1C = a->unkC;
    if (a->unk4 == 0) {
        inl_800FB080(a, p);
    } else if (p->unk9A == 0) {
        a->unk3 = 0;
        a->unk4 = 0;
    } else {
        D_800FE7F8_ovl28[a->unk5](a, p);
    }
}
