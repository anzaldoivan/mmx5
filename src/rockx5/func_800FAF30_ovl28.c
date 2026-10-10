#include "types.h"

// from rockx5 800FAF30_ovl28
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ u8 pad6[2];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[5];
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16[2];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x18];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[7];
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 pad48[8];
    /* 0x50 */ void* unk50;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ u8 pad5A[0x40];
    /* 0x9A */ s8 unk9A;
} ObjFAF30;

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
