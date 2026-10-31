#include "types.h"

extern s8 D_800D1D0D;
extern u8 D_8009A0A0[];
extern void (*D_800712E8[])(u8*, u8*);

void func_80022C84(u8* arg0) {
    u8* p;

    if (D_800D1D0D == 0) {
        p = D_8009A0A0;
        arg0[0x47] = p[0x47];
        arg0[0x15] = p[0x15];
        *(s32*)(arg0 + 0x38) = *(s32*)(p + 0x38);
        *(s32*)(arg0 + 0x3C) = *(s32*)(p + 0x3C);
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        if (*(s8*)(arg0 + 4) == 0) {
            if (*(s8*)(p + 0x8C) != 0) {
                if (*(s8*)(p + 0x8C) > 0) {
                    arg0[3] = 1;
                    *(s16*)(arg0 + 0x54) = 3;
                    *(s16*)(arg0 + 0x56) = 8;
                    *(s16*)(arg0 + 0x58) = (5 - *(s8*)(arg0 + 2)) * 2;
                    *(s32*)(arg0 + 0x8) = *(s32*)(p + 0x8);
                    *(s32*)(arg0 + 0xC) = *(s32*)(p + 0xC);
                    arg0[4] = 1;
                    arg0[5] = 0;
                    return;
                }
                p[0x8C] = 0;
            }
        } else {
            if (*(s8*)(p + 0x8C) == 0) {
                arg0[3] = 0;
                arg0[4] = 0;
                return;
            }
            D_800712E8[*(s8*)(arg0 + 5)](arg0, p);
        }
    }
}
