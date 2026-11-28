#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl25.h"

#define D_800F5024_ovl24 D_800F0734_ovl25

#define func_800EFFBC_ovl24 func_800F0228_ovl25
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

extern s32 D_800D1DB4;

void func_800F0264_ovl25(u8* arg0) {
    u8* p;

    arg0[1]++;
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 1;
        *(s32*)(p + 0x54) = D_800D1DB4;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 9;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 7;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x38;
        p[2] = 8;
    }
}

extern void func_800132F8(s8 arg);

void func_800F035C_ovl25(u8* arg0) {
    if (D_800C9320.h != 0) {
        func_800132F8(8);
        arg0[1] = 10;
    } else if (--*(s16*)(arg0 + 4) == 0) {
        arg0[1]++;
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800F1EF4_ovl25[];

void func_800F03C4_ovl25(Ovl25State* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    *(s32*)((u8*)p + 0x5C) += 0x8000;
    p->unkA0 = 1;
    if (p->unk5E >= 0x1B20) {
        func_8002C3CC(D_800F1EF4_ovl25, D_800F1CF4_ovl25, 0x100, ++arg0->unk4,
                      0x40);
        ((s32(*)())load_palette)(0x90, D_800F1EF4_ovl25, 0x10);
        if (arg0->unk4 >= 0x41) {
            *(s16*)((u8*)p + 0xB2) = 0xA00;
            p->unkF4 = 1;
            arg0->unk4 = 0;
            ((u8*)arg0)[1]++;
        }
    }
}

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_800F22F4_ovl25[];

void func_800F049C_ovl25(u8* arg0) {
    u8* p;

    p = D_8009A1F8.u;
    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += 0x8000;
    func_8002C3CC(D_800F22F4_ovl25, D_800F20F4_ovl25, 0x100,
                  0x40 - ++*(s16*)(arg0 + 4), 0x40);
    ((s32(*)())load_palette)(0xA0, D_800F22F4_ovl25, 0x10);
    if (*(s16*)(arg0 + 4) > 0x40) {
        ((s32(*)())load_palette)(0xA0, D_800F20F4_ovl25, 0x10);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}

extern void func_800132F8(s8 arg);

void func_800F056C_ovl25(Ovl25State* arg0) {
    D_8009A1F8_t* p = &D_8009A1F8.t;

    if (p->unk5E < 0x1C01) {
        p->unkA0 = 1;
        *(s32*)((u8*)p + 0x5C) += 0x8000;
    }
    if (D_800C9320.h != 0) {
        func_800132F8(8);
        ((u8*)arg0)[1] = 10;
    }
}

extern void func_80017D88(void);
extern void create_task(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_8001E534(void);
extern s8 D_8009A424;
extern u8 D_800D1F28[];
extern u8 D_800F24F4_ovl25;
extern s32 D_80091D54;

void func_800F05E0_ovl25(void) {
    if (D_8009A424 == 0) {
        D_800D1F28[0] = 3;
        D_800D1F28[1] = 0;
        D_800D1F28[2] = 0;
        D_800D1F28[3] = 0;
        D_800F24F4_ovl25 = 1;
        D_80091D54 = 0;
        func_80017D88();
        create_task(0, func_8001E534);
        func_80012EAC();
    }
}
