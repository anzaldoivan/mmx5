/* Shared body (DK-5), from the banked draft of func_800F1480_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* o) {
    u8* src;

    src = *(u8**)(o + 0x7C);
    *(u16*)(o + 0x40) = *(u16*)(src + 0x40);
    *(u16*)(o + 0x42) = *(u16*)(src + 0x42) & 0x7FFF;
    *(s32*)(o + 0x30) = *(s32*)(src + 0x30);
    *(s32*)(o + 0x3C) = *(s32*)(src + 0x3C);
    o[0x14] = 0;
    o[0x16] = 1;
    o[0x15] = src[0x15];
    o[0x67] = 0;
    o[0x3] = 0;
    *(s32*)(o + 0x68) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x58) = 0;
    DEDUP_CALLEE(o, 0x11);
    *(s16*)(o + 0xE) = *(u16*)(*(u8**)(o + 0x7C) + 0xE) - 0x36;
    o[0x5C] = 1;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x60] = 8;
    *(s32*)(o + 0x8C) = 0;
    o[0x4]++;
    o[0x5] = 0;
}
