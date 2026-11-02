#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 D_800FB2B4_ovl00[];
extern s32 D_800FB2D4_ovl00[];
extern s32 D_800FB2F4_ovl00[];
extern s32 D_800FB314_ovl00[];
extern s32 D_800FB334_ovl00[];
extern s16 D_800FB354_ovl00[];

void func_800F5988_ovl00(u8 n, s32 arg1, u8* parent, s8 flag) {
    u8* p;
    s32 t;
    s32 u;

    for (; n != 0; n--) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 4;
            p[0x15] = func_8002DF78() & 0x40;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            *(s32*)(p + 0x20) = 0;
            *(s32*)(p + 0x28) = 0;
            *(s32*)(p + 0x24) = 0;
            *(s32*)(p + 0x2C) = 0;
            if (flag != 0) {
                if (func_8002DF78() & 1) {
                    *(s32*)(p + 8) = *(s32*)(parent + 8) +
                                     ((*(u8**)(parent + 0x68))[2] << 16) +
                                     D_800FB314_ovl00[func_8002DF78() & 7] / 2;
                } else {
                    *(s32*)(p + 8) = *(s32*)(parent + 8) -
                                     ((*(u8**)(parent + 0x68))[2] << 16) +
                                     D_800FB314_ovl00[func_8002DF78() & 7] / 2;
                }
                *(s32*)(p + 0xC) = *(s32*)(parent + 0xC) +
                                   D_800FB334_ovl00[func_8002DF78() & 7];
                t = D_800FB354_ovl00[func_8002DF78() & 7];
                p[0x47] = 2;
                *(s32*)(p + 0x2C) = t;
            } else {
                *(s32*)(p + 8) =
                    *(s32*)(parent + 8) + D_800FB2F4_ovl00[func_8002DF78() & 7];
                *(s32*)(p + 0xC) = *(s32*)(parent + 0xC) +
                                   D_800FB334_ovl00[func_8002DF78() & 7];
                *(s32*)(p + 0x2C) = 0x5000;
                *(s32*)(p + 0x20) += D_800FB2B4_ovl00[func_8002DF78() & 7];
                u = D_800FB2D4_ovl00[func_8002DF78() & 7];
                p[0x47] = 3;
                *(s32*)(p + 0x24) = u;
            }
        }
    }
}
