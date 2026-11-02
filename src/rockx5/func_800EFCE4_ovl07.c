#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_8002B5B4(s32);
extern u8* func_8002D078();
extern u8* func_8002D0E4(void);
extern u8 D_800D1D10;

void func_800EFCE4_ovl07(u8* arg0, u8 arg1) {
    u8* p;
    s32 r;

    if (((*(u16*)(arg0 + 0x8C) & 0x30) ||
         ((*(u16*)(arg0 + 0x8A) & 0x30) && (D_800D1D10 & 2))) &&
        arg0[0x89] == 0 && arg0[0x98] < 3) {
        p = func_8002D078();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x38;
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
            *(u8**)(p + 0x7C) = arg0;
            p[0x15] = arg0[0x15];
        }
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0xC;
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
        arg0[0x89] = 4;
        arg0[0x98]++;
        func_80016490(5, 0x13, arg0);
    }
}
