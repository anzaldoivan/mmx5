#include "types.h"

extern ObjFAF38* func_8002D1A4();
extern u8 D_800FB410_ovl09[];

void func_800F8ED0_ovl09(ObjFAF38* a, u8 b) {
    ObjFAF38* p = func_8002D1A4();

    if (p != 0) {
        p->unk0 = 0x41;
        p->unk1 = 0x13;
        p->unk7C = a;
        p->unk2 = b;
        ((u8*)p)[0x15] = ((u8*)a)[0x15];
        p->unkA = a->unkA;
        p->unk8 = 0;
        p->unkE = a->unkE;
        p->unkC = 0;
        p->unk42 = a->unk42 & 0x7FFF;
        p->unk30 = (s32)D_800FB410_ovl09;
        p->unk3C = a->unk3C;
        p->unk40 = a->unk40;
        p->unk14 = a->unk14;
    }
}
