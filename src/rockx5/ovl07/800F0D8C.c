#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

extern u8 D_8009A175;

void func_800F0D8C_ovl07(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0xA0000;
    *(s32*)(arg0 + 0x24) = 0;
    arg0[5]++;
    D_8009A175 = 0;
    func_8003D29C(0x17, 0x40);
}

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800F0DD0_ovl07(u8* arg0) {
    if (*(s16*)(arg0 + 0xA) >= 0x1EFB) {
        play_sound(5, 0x14, 0);
        arg0[5]++;
        *(s16*)(arg0 + 0x9C) = 0;
        func_8002C218();
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
    } else {
        move_object(arg0);
    }
}

extern void start_pad_vibration(s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8002C1C8(void);
extern u8 D_801007DC_ovl07[];

void func_800F0E6C_ovl07(u8* a0) {
    if ((u16)++ * (u16*)(a0 + 0x9C) >= 6) {
        start_pad_vibration(3);
        a0[5]++;
        func_8004FD90(a0, 1, 0x20, 0x20);
        func_8004FD90(a0, 1, 0x20, 0x20);
        *(s32*)(a0 + 0x20) = 0xFFFC0000;
        func_8004D4F4(0xB, D_801007DC_ovl07, a0);
        a0[3] = 0;
        *(u16*)(a0 + 0x9C) = 0;
        func_8002C1C8();
    }
}

extern void func_8002A600(s32, s32, s32);
extern void func_8002A5C4(s32, s32, s32);

void func_800F0F10_ovl07(u8* p) {
    (*(u16*)(p + 0x9C))++;
    if (*(u16*)(p + 0x9C) < 120) {
        if ((*(volatile u16*)(p + 0x9C) & 7) ==
            0) { // !FAKE: volatile re-read of the counter
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
            func_8004FD90(p, 1, 0x30, 0x30);
        }
    } else {
        *(u16*)(p + 0x9C) = 0;
        p[5]++;
        func_8002A600(100, 3, 2);
        func_8002A5C4(100, 2, 1);
        *(s16*)(p + 0xE) = 0xD0;
    }
}

void func_800F0FE8_ovl07(u8* arg0) {
    u8* p;

    if ((u16)++ * (u16*)(arg0 + 0x9C) >= 0x5A) {
        p = g_playthrough_state.u;
        if ((p[0xA1] & 1) || ((s8*)p)[0x26] == 0) {
            arg0[5] = 9;
        } else {
            ((s32(*)())func_8002385C)(0x37, 0xFF, 0);
            arg0[5]++;
        }
    }
}

extern u8 D_80091C44;
extern u8* func_8002D33C(u8* p, s32 backward);

void func_800F1078_ovl07(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = func_8002D33C(0, 1);
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x3B;
            p[2] = 0;
        }
        ((s32(*)())func_8003D29C)(0x1F, 0x40);
        arg0[5]++;
    }
}

void func_800F10E8_ovl07(u8* arg0) {
    u8* p;

    p = g_playthrough_state.u;
    if (((s8*)p)[0x27] == 3) {
        if (((s8*)p)[0x26] == 8) {
            func_8002385C(0x38, 0xFF, 0);
        } else {
            func_8002385C(0x39, 0xFF, 0);
        }
        arg0[5]++;
    }
}

/* Adapted from mmx6 @c1c892d src/shared/rock_02/func_800F9F3C.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80091C44;

void func_800F1164_ovl07(void* arg0) {
    if (D_80091C44 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
#undef M2C_FIELD

extern void func_80017768(void);

void func_800F1190_ovl07(u8* a0) {
    ((s32(*)())func_8003D2C4)();
    a0[4] = 3;
    a0[5] = 0;
    func_80017768();
}
