#include "types.h"
#include "mmx5/ovl24.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

#define D_800D1C28_as_u8 (*(u8*)&D_800D1C28)

extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);
extern u8 D_80091C44;
extern u8 D_8009A427;

void func_800EEF10_ovl24(u8* arg0) {
    u8 state;

    if (D_80091C44 == 0) {
        D_800D1C28_as_u8 = 1;
        D_8009A427 = 0;
        state = arg0[0xC0];
        if (state < 4) {
            D_800F5F80_ovl24 = 0;
            func_800F0C00_ovl24((s32)arg0, 0x1E, 1);
        } else if (state < 8) {
            D_800F5F80_ovl24 = 1;
            func_800F0C00_ovl24((s32)arg0, 0x13, 1);
            func_800F0C00_ovl24((s32)arg0, 0x8E, 1);
            func_800F0C00_ovl24((s32)arg0, 0x14, 1);
            func_800F0C00_ovl24((s32)arg0, 0x15, 1);
        } else {
            D_800F5F80_ovl24 = 2;
            func_800F0C00_ovl24((s32)arg0, 0x13, 1);
            func_800F0C00_ovl24((s32)arg0, 0x8E, 1);
            func_800F0C00_ovl24((s32)arg0, 0x1F, 1);
            func_800F0C00_ovl24((s32)arg0, 0x20, 1);
        }
        arg0[2]++;
    }
}
#undef D_800D1C28_as_u8

#define D_800F5F80_ovl24_as_s8 (*(s8*)&D_800F5F80_ovl24)

extern void func_800F0C00_ovl24(s32 a0, u8 a1, s8 a2);
extern u8 D_8009A427;
extern s8 D_800F5F7A_ovl24;

void func_800EF028_ovl24(s32 arg0) {
    u16* pad;

    if (D_800C931C[2] & 0x5000) {
        if (D_800F5F80_ovl24_as_s8 != 0) {
            play_sound(0, 0xC, 0);
        }
        D_8009A420[7] ^= 1;
    }
    pad = D_800C931C;
    if (D_800F5F80_ovl24_as_s8 != 0) {
        if (!(pad[2] & 0x40)) {
            return;
        }
        play_sound(0, 0x22, 0);
        if (D_8009A427 == 0) {
            D_800F5F7A_ovl24 = 1;
        } else {
            goto two; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        if (!(pad[2] & 0x8FF)) {
            return;
        }
        if (D_8009A427 == 0) {
            D_800F5F7A_ovl24 = 1;
        } else {
        two: // !FAKE: label kept for the matching branch layout
            D_800F5F7A_ovl24 = 2;
        }
    }
    func_800F0C00_ovl24(arg0, 0xDE, 1);
    ((u8*)arg0)[2]++;
}
#undef D_800F5F80_ovl24_as_s8

extern void func_800F0C58_ovl24(u8* a0, s32 a1, s32 a2, s32 a3);
extern u8 D_8009A169;
extern u8 D_800D1C00[];
extern u16 D_800F4E74_ovl24;
extern u16 D_800F5F74_ovl24;
extern s16 D_800F5F76_ovl24;
extern s16 D_800F5F78_ovl24;

void func_800EF14C_ovl24(u8* arg0) {
    u8* p = D_800D1C00;

    p[0x28] = 1;
    if (p[0xA1] != p[0xCC]) {
        func_800F0C58_ovl24(arg0, 0x8F, 1, 0);
        func_800F0C58_ovl24(arg0, 0x91, 2, 0);
        func_800F0C58_ovl24(arg0, 0x90, 3, 0);
        D_800F5F78_ovl24 = 3;
        if (((s8*)p)[0x27] == 0) {
            if (!((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
                func_800F0C58_ovl24(arg0, 0x93, 4, 0);
                func_800F0C58_ovl24(arg0, 0x92, 5, 0);
                D_800F5F78_ovl24 = 5;
            }
        }
    } else if (((s8*)p)[0x27] == 0 &&
               !((D_8009A169 >> (((s8*)p)[0x26] - 1)) & 1)) {
        func_800F0C58_ovl24(arg0, 0x8F, 1, 0);
        func_800F0C58_ovl24(arg0, 0x93, 2, -0x10);
        func_800F0C58_ovl24(arg0, 0x92, 3, -0x10);
        D_800F5F78_ovl24 = 3;
    } else {
        arg0[1] = 3;
        arg0[2] = 0;
        return;
    }
    D_800F5F76_ovl24 = 0;
    D_800F5F74_ovl24 = D_800F4E74_ovl24;
    arg0[2]++;
}

#define D_800F4E60_ovl24 D_800F4E74_ovl24

#define func_800EEE3C_ovl24 func_800EF2E8_ovl24
#include "shared/func_800EEE3C_ovl24.c"
#undef func_800EEE3C_ovl24
