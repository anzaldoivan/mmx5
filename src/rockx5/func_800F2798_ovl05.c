#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern s32 func_8002DF78(void);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_8009A1F8[];
extern u8 D_800F57DC_ovl05[];
extern s32 D_800F581C_ovl05[];
extern s32 D_800F583C_ovl05[];

void func_800F2798_ovl05(u8* a0) {
    s8 st;
    u8 r;
    u8* g;
    u8* h;
    u8* k;

    st = ((s8*)a0)[2];
    if (st >= 0) {
        if (st < 3) {
            a0[5] = 0;
        } else if (st < 5) {
            r = func_8002B5B4(0x25);
            *(u16*)(a0 + 0x40) = D_80098118[r] >> 7;
            *(s32*)(a0 + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[r];
            *(u16*)(a0 + 0x42) =
                ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
            a0[0x14] = D_8009A0B4;
            a0[0x16] = 0;
            *(u8**)(a0 + 0x30) = D_800F57DC_ovl05;
            *(u16*)(a0 + 0xA) = *(u16*)(*(u8**)(a0 + 0x50) + 0xA);
            if (func_8002DF78() & 4) {
                g = D_8009A1F8;
                *(u16*)(a0 + 0xE) =
                    *(u16*)(g + 0xE) - ((func_8002DF78() & 0x3F) - 0x78);
            } else {
                h = D_8009A1F8;
                *(u16*)(a0 + 0xE) =
                    *(u16*)(h + 0xE) + ((func_8002DF78() & 0x3F) + 0x78);
            }
            *(s32*)(a0 + 0x2C) = 0x5000;
            *(s32*)(a0 + 0x28) = 0;
            if (((s8*)a0)[2] == 3) {
                *(s32*)(a0 + 0x20) = D_800F581C_ovl05[func_8002DF78() & 3];
            } else {
                *(s32*)(a0 + 0x20) = D_800F581C_ovl05[func_8002DF78() & 7];
            }
            *(s32*)(a0 + 0x24) = D_800F583C_ovl05[func_8002DF78() & 7];
            a0[0x15] = 0;
            func_800171E8(a0, (func_8002DF78() & 3) + 5);
            a0[5] = 1;
            k = D_8009A1F8;
            if (*(s16*)(k + 0xE) < 0xA60) {
                a0[4]++;
            }
        }
    }
    a0[4]++;
}
