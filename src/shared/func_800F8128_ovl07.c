/* Shared body (DK-5), from the banked draft of func_800F8128_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_8002D6FC(u8* obj);
extern s32 func_800F7FF4_ovl07(u8*, s32, s32);
extern u8 D_80076CE0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_800C6A10[];
extern signed char D_800D1C0C;
extern Blk4 D_801016D0_ovl07;
extern u8 D_801016D4_ovl07[];

void DEDUP_NAME(u8* p) {
    s32 r;

    p[4] = 1;
    p[5] = 2;
    p[6] = 2;
    p[0] = 0x41;
    p[0x15] = 0;
    p[0x14] = D_8009A0B4;
    *(s16*)(p + 0x40) = D_80098118[func_8002B5B4(0x98)] >> 7;
    *(s32*)(p + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x98)];
    r = func_8002B5B4(0x98);
    *(s16*)(p + 0x42) =
        ((r * 4 + 0x18) % 16) | (((func_8002B5B4(0x98) + 6) / 4 + 0x1E0) << 6);
    if (D_800D1C0C == 7) {
        p[0x16] = 0x20;
    } else {
        p[0x16] = 0x37;
    }
    p[0x47] = 0;
    p[0x5C] = 8;
    *(u8**)(p + 0x58) = D_80076CE0;
    *(u8**)(p + 0x68) = p + 0x80;
    *(Blk4*)(p + 0x80) = D_801016D0_ovl07;
    *(u8**)(p + 0x54) = D_801016D4_ovl07;
    *(s32*)(p + 0x50) = 0;
    p[0x61] = 0;
    p[0x75] = 1;
    p[0x60] = 0x10;
    p[0x65] = 0;
    p[0xA2] = 1;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    p[0x85] = 0;
    if (func_800F7FF4_ovl07(p, *(s16*)(p + 0xA), *(s16*)(p + 0xE)) != 0) {
        p[4] = 2;
    }
    if (((s8*)p)[2] == 0x11) {
        Blk0A4* d = (Blk0A4*)D_800C6A10;
        d[63] = *(Blk0A4*)p;
        func_8002D6FC(p);
    }
}
