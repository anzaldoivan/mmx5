#include "types.h"
#include "addr.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002B5B4(s32);
extern u32* D_80098118;

void func_8004D97C(u8 n, u8* bytes, u8* src, s32 seed, s32 arg4) {
    u8* p;
    s32 a;
    s32* base;

    while (n != 0) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 3;
            p[2] = 1;
            p[0x15] = func_8002DF78() & 0x40;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            *(s32*)(p + 8) = *(s32*)(src + 8) + ((func_8002DF78() & 3) << 16);
            *(s32*)(p + 0xC) =
                *(s32*)(src + 0xC) + ((func_8002DF78() & 3) << 16);
            p[0x58] = *bytes++;
            *(u8**)(p + 0x54) = src;
            *(s32*)(p + 0x30) = arg4;
            *(s16*)(p + 0x42) = ((func_8002B5B4(seed) * 4 + 0x18) % 16) |
                                (((func_8002B5B4(seed) + 6) / 4 + 0x1E0) << 6);
            *(s16*)(p + 0x40) = D_80098118[func_8002B5B4(seed)] >> 7;
            a = func_8002B5B4(seed);
            base = D_1F800020.s32s;
            *(s32*)(p + 0x3C) = (s32)base + base[a];
        }
        n--;
    }
}
