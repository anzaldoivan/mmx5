/* Shared body (DK-5), from the banked draft of func_800F12BC_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_800F20C8_ovl12[];

void DEDUP_NAME(u8* obj) {
    *(u16*)(obj + 0x40) = *(u16*)(*(u8**)(obj + 0x7C) + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(*(u8**)(obj + 0x7C) + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(*(u8**)(obj + 0x7C) + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(*(u8**)(obj + 0x7C) + 0x3C);
    obj[0x14] = 0;
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x50) = D_800F20C8_ovl12;
    *(s32*)(obj + 0x54) = 0;
    *(s32*)(obj + 0x58) = 0;
    DEDUP_CALLEE(obj, 0x10);
    *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x7C) + 0xE) + 0x12;
    if (*(s8*)(obj + 0x2) == 2) {
        obj[0x15] = 0;
        *(s32*)(obj + 0x20) = 0xFFFC0000;
    } else {
        obj[0x15] = 0x40;
        *(s32*)(obj + 0x20) = 0x40000;
    }
    obj[0x5C] = 1;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x60] = 4;
    *(s32*)(obj + 0x8C) = 0;
    obj[0x5] = 0;
    obj[0x4]++;
}
