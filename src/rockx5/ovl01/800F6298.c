#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

extern u8 D_8009A197;
extern u8 D_800FCF80_ovl01[];
extern void (*D_800FD244_ovl01[])(Obj6298*);
extern void func_8004D4F4(s32 a0, void* a1, Obj6298* a2);

void func_800F6298_ovl01(Obj6298* obj) {
    if (D_8009A197 == 0) {
        obj->unk18 = obj->x_pos;
        obj->unk1C = obj->y_pos;
        D_800FD244_ovl01[obj->unk5](obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(2, D_800FCF80_ovl01, obj);
        obj->unk3 = 0;
        obj->unk7C = 0xF;
        obj->unk7E = 5;
        obj->state = 7;
    } else {
        func_8002D9EC(obj, 0x40, 0x20);
        func_800F6BDC_ovl01(obj);
    }
}

extern u8 D_8009A197;
extern void (*D_800FD258_ovl01[])(u8*);

void func_800F6360_ovl01(u8* a0) {
    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        D_800FD258_ovl01[*(s8*)(a0 + 5)](a0);
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_8002D9EC(a0, 0x40, 0x20);
    func_800F6BDC_ovl01(a0);
}

extern void (*D_800FD2B4_ovl01[])(u8*);
extern s16 D_800FD204_ovl01[][2];

void func_800F63E4_ovl01(u8* a0) {
    u8* base = g_Player;
    s16 v;
    s32 i;

    if (base[0xF7] == 0) {
        D_800FD2B4_ovl01[((s8*)a0)[5]](a0);
    }
    i = a0[2] & 0xF;
    v = *(s16*)(base + 0xA);
    if (v >= D_800FD204_ovl01[i][0] && v <= D_800FD204_ovl01[i][1]) {
        a0[3] = 1;
    } else {
        a0[3] = 0;
    }
}

#define D_800EEBA0_ovl00 func_800F6494_ovl01
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

extern void func_80054440(u8* a0, s32 a1);

void func_800F64B4_ovl01(Obj800F2688* obj) {
    if (--obj->unk7C == 0) {
        func_80054440((u8*)obj, 0x12);
        obj->unk4 = 6;
    } else if (--obj->unk7E == 0) {
        func_8004FD90(obj, 1, 0x10, 0x10);
        obj->unk7E = 5;
    }
}

extern int func_8002D7A0();

void func_800F6538_ovl01(u8* a0) {
    s8 state = ((s8*)a0)[5];

    if (state == 0) {
        if (is_off_screen(a0, 0x30, 0x30) == 0) {
            func_8002D9EC(a0, 0x20, 0x20);
        } else {
            a0[5]++;
        }
    } else if (state == 1) {
        func_8002D7A0(a0);
    }
}

extern s16 D_8009A220[];

void func_800F65B4_ovl01(void) {
    if ((u16)(D_8009A0AA - 0x8C0) < 0xA9) {
        D_8009A220[1] = 0x60;
    }
}
