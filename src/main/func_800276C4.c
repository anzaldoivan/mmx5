#include "types.h"
#include "addr.h"

extern u8 D_8009A430[];
extern u8 D_800BE9B0[];
extern u8 D_800D15A0[][6][0x88];
extern s32 D_800E92F8;

void func_800276C4(s32 arg0, s32 arg1) {
    u32 i;
    u32 j;
    u32 k;
    u16 x;
    u8* p;

    D_800E92F8 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 0x400; j++) {
            p = &D_800BE9B0[(i << 14) + (j << 4)];
            p[3] = 3;
            p[7] = 0x7D;
        }
        for (j = 0; j < 6; j++) {
            p = D_800D15A0[i][j];
            x = 0x140;
            for (k = 0; k < 8; k++) {
                p[3] = 1;
                *(u32*)(p + 4) = ((arg0 & 3) << 7) | ((arg1 & 3) << 5) |
                                 (((x & 0x3FF) >> 6) | 0x10) | 0xE1000000;
                p += 8;
                x += 0x40;
            }
        }
        for (j = 0; j < 6; j++) {
            p = &D_800D15A0[i][j][0x40];
            x = 0x140;
            for (k = 0; k < 4; k++) {
                p[3] = 1;
                *(u32*)(p + 4) = ((arg1 & 3) << 5) |
                                 (((x & 0x3FF) >> 6) | 0x90) | 0xE1000000;
                p += 8;
                x += 0x80;
            }
        }
        for (j = 0; j < 6; j++) {
            p = &D_800D15A0[i][j][0x60];
            x = 0x180;
            for (k = 0; k < 5; k++) {
                p[3] = 1;
                *(u32*)(p + 4) = ((arg1 & 3) << 5) |
                                 (((x & 0x3FF) >> 6) | 0x80) | 0xE1000000;
                p += 8;
                x += 0x80;
            }
        }
    }
    D_1F800004 = D_8009A430;
}
