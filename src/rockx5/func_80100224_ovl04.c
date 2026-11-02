#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern u8 D_80076B00[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_80102F48_ovl04[];
extern u8 D_80102F5C_ovl04[];

void func_80100224_ovl04(u8* o) {
    s32 r;
    s32 v;
    u8 t;

    o[0] = 0x41;
    o[0x15] = 0;
    *(s16*)(o + 0x40) = D_80098118[func_8002B5B4(0x92)] >> 7;
    *(s32*)(o + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x92)];
    r = func_8002B5B4(0x92);
    *(s16*)(o + 0x42) =
        ((r * 4 + 0x18) % 16) | (((func_8002B5B4(0x92) + 6) / 4 + 0x1E0) << 6);
    o[0x75] = 0;
    o[0x76] = 0;
    o[0x67] = 0;
    *(u8**)(o + 0x30) = D_80102F48_ovl04;
    t = D_8009A0B4;
    v = 6;
    o[0x16] = v;
    v = 8;
    o[0x5C] = v;
    v = (s32)D_80076B00;
    *(s32*)(o + 0x58) = v;
    v = (s32)D_80102F5C_ovl04;
    *(s32*)(o + 0x54) = v;
    v = 1;
    o[0x60] = 0;
    o[0x61] = 0;
    o[0x65] = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x68) = 0;
    o[0x47] = 0;
    o[3] = 0;
    o[4] = v;
    o[5] = 0;
    o[6] = 0;
    o[0x14] = t;
}
