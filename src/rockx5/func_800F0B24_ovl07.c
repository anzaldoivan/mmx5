#include "types.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D0E4(void);

void func_800F0B24_ovl07(u8* arg0, u8 arg1) {
    u8* p;
    s32 r;

    p = func_8002D0E4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xD;
        p[2] = arg1;
        *(u16*)(p + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(arg0 + 0xE);
        *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
        *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
        *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
        r = func_8002B5B4(0x82);
        *(s16*)(p + 0x42) =
            ((r * 4 + 0x18) % 16) | (((r + 6) / 4 + 0x1E0) << 6);
        p[0x16] = arg0[0x16];
        *(u8**)(p + 0x50) = arg0;
        p[0x15] = arg0[0x15];
    }
}
