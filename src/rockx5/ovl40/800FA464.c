#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;
extern s32 D_800FA688_ovl40;

void func_800FA464_ovl40(Ovl45State* a0) {
    D_8009A1F8_8_t* p;

    if (D_80091C44 == 0) {
        D_800FA688_ovl40 = 0x700000;
        a0->unk4 = 0x3C;
        p = &D_8009A1F8.t8;
        ((s16*)&p->unk8)[1] = 0x220;
        ((u8*)p)[3] = 1;
        ((s16*)p)[7] = 0;
        ((u8*)p)[0x4C] = 1;
        p->unk8 += 0x700000;
        a0->unk1++;
    }
}

extern s32 D_800FA688_ovl40;

void func_800FA4D0_ovl40(Ovl45State* a0) {
    D_8009A1F8_8_t* p;
    D_8009A1F8_8_t* q;
    s32 v;

    a0->unk4--;
    p = &D_8009A1F8.t8;
    ((s16*)&p->unk8)[1] = 0x220;
    v = D_800FA688_ovl40 - 0x1DC28;
    D_800FA688_ovl40 = v;
    if (a0->unk4 & 1) {
        p->unk8 -= v;
    } else {
        p->unk8 += v;
    }
    q = &D_8009A1F8.t8;
    ((u8*)q)[0x4C] = 1;
    if (a0->unk4 == 0) {
        func_8002385C(3, 0xFF, 0);
        ((s16*)&q->unk8)[1] = 0x220;
        a0->unk1++;
    }
}

#include "shared/func_800FA594_ovl40.c"

extern signed char D_8009A424;

void func_800FA5D8_ovl40(u8* a0) {
    s32 i;
    u8* p;

    if (D_8009A424 == 0) {
        func_8001E668();
        p = D_8009A1F8.u;
        p[3] = 0;
        p[0x57] = 0;
        p[0xAB] = 0;
        func_8002C50C();
        a0[0xC] = 0;
        a0[0xD] = 0;
        a0[0] = 7;
        a0[1] = 0;
        a0[2] = 0;
        a0[3] = 0;
        for (i = 0; i < 16; i++) {
            a0[0x26 + i] = 0;
        }
    }
}
