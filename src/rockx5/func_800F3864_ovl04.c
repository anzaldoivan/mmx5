#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8* func_8002D0E4(void);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern u32* D_80098118;
extern u8 D_8009A0B4;

void func_800F3864_ovl04(u8* o) {
    u8* p;
    u8* q;
    s32 r;

    if (*(s16*)(o + 0x7C) < 0x78) {
        *(s16*)(o + 0x7C) += 1;
    } else {
        o[5] = 4;
    }
    if ((o[0x7C] & 7) == 0) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 4;
            p[2] = 0;
            p[4] = 0;
            p[5] = 0;
            p[6] = 0;
            *(s16*)(p + 0xA) = func_8002DFB0() % 80 + 0x1230;
            *(s16*)(p + 0xE) = func_8002DFB0() % 128 + 0x3F8;
            p[0x15] = 0;
            p[0x14] = 0;
            p[0x16] = 1;
        }
        q = func_8002D27C();
        if (q != 0 && *(s16*)(o + 0x7C) < 0x3C) {
            q[0] = 0x41;
            q[1] = 0x31;
            q[0x15] = func_8002DF78() & 0x40;
            q[2] = 2;
            *(s16*)(q + 0xA) = func_8002DFB0() % 80 + 0x1230;
            *(s16*)(q + 0xE) = func_8002DFB0() % 128 + 0x3F8;
            *(s16*)(q + 0x40) = D_80098118[func_8002B5B4(0x92)] >> 7;
            *(s32*)(q + 0x3C) =
                (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x92)];
            r = func_8002B5B4(0x92);
            *(s16*)(q + 0x42) = ((r * 4 + 0x18) % 16) |
                                (((func_8002B5B4(0x92) + 6) / 4 + 0x1E0) << 6);
            q[0x14] = D_8009A0B4;
        }
    }
}
