#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D210();
extern u8 D_8009A0B4;
extern u32* D_80098118;
extern u8 D_800767E0[];
extern s32 D_800FB380_ovl00[];
extern s32 D_800FB384_ovl00[];
extern s32 D_800FB388_ovl00[];
extern s32 D_800FB38C_ovl00[];
extern s32 D_800FB394_ovl00[];
extern s32 D_800FB398_ovl00[];

void func_800F6324_ovl00(u8* a0) {
    s32 r;
    s32 r2;
    s32 i;
    u8* o;
    u32* t;

    a0[4] = 1;
    a0[5] = 2;
    a0[6] = 0;
    a0[0] = 0x41;
    a0[0x14] = D_8009A0B4;
    *(u16*)(a0 + 0x40) = D_80098118[func_8002B5B4(0x88)] >> 7;
    r = func_8002B5B4(0x88);
    t = D_1F800020.u32s;
    *(s32*)(a0 + 0x3C) = (s32)t + t[r];
    r = func_8002B5B4(0x88);
    r2 = func_8002B5B4(0x88);
    *(s16*)(a0 + 0x42) = ((r * 4 + 0x18) % 16) | (((r2 + 6) / 4 + 0x1E0) << 6);
    a0[0x16] = 6;
    a0[0x60] = 0x7F;
    a0[0x61] = 0;
    *(u8**)(a0 + 0x58) = D_800767E0;
    a0[0x65] = 0;
    a0[0x75] = 1;
    *(s32*)(a0 + 0x20) = 0;
    *(s32*)(a0 + 0x24) = 0;
    a0[0x80] = 0;
    a0[0x81] = 0;
    switch (*(s8*)(a0 + 2)) {
    case 0:
        *(s32**)(a0 + 0x68) = D_800FB380_ovl00;
        *(s32**)(a0 + 0x54) = D_800FB38C_ovl00;
        a0[0x47] = 4;
        *(s16*)(a0 + 0xE) = 0x368;
        break;
    case 1:
        *(s32**)(a0 + 0x68) = D_800FB388_ovl00;
        *(s32**)(a0 + 0x54) = D_800FB398_ovl00;
        a0[0x47] = 3;
        *(s16*)(a0 + 0xE) = 0x1D0;
        break;
    case 2:
        *(s16*)(a0 + 0xA) = 0x1098;
        *(s16*)(a0 + 0xE) = 0x2A0;
        *(s32**)(a0 + 0x68) = D_800FB384_ovl00;
        *(s32**)(a0 + 0x54) = D_800FB394_ovl00;
        a0[0x47] = 1;
        for (i = 0; i < 2; i++) {
            o = func_8002D210();
            if (o != 0) {
                o[0] = 0x41;
                *(s32*)(o + 0x68) = 0;
                *(s32**)(o + 0x54) = D_800FB394_ovl00 - 1;
                o[1] = 3;
                o[2] = 0x7E;
                *(u8**)(o + 0x7C) = a0;
                *(s16*)(o + 0xA) = 0x1098;
                if (i == 0) {
                    o[0x47] = 0;
                    *(s16*)(o + 0xE) = 0x260;
                }
                if (i == 1) {
                    *(s16*)(o + 0xE) = 0x2E0;
                    o[0x47] = 2;
                }
            }
        }
        break;
    case 0x70:
        a0[0x47] = 3;
        a0[4] = 2;
        *(s16*)(a0 + 0xA) = 0x1090;
        *(s16*)(a0 + 0xE) = 0x1D0;
        break;
    case 0x71: // !FAKE: empty case balances the case tree to root 2
        break;
    }
}
