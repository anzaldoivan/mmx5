/* Shared body (DK-5), from the banked draft of func_800F09C8_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_80074DA0[];
extern u8 D_800F5360_ovl05[];
extern u8 D_800F5364_ovl05[];
extern u8 D_800F5368_ovl05[];
extern u8 D_800F536C_ovl05[];
extern u8 D_800F5370_ovl05[];

void DEDUP_NAME(u8* obj) {
    u8* p;
    s8 st;

    *(u8**)(obj + 0x58) = D_80074DA0;
    p = *(u8**)(obj + 0x7C);
    obj[3] = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x16] = 0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
    st = *(s8*)(obj + 2);
    obj[0x67] = 1;
    if (st == 0) {
        *(u8**)(obj + 0x50) = D_800F5360_ovl05;
        *(s32*)(obj + 0x54) = 0;
        *(u8**)(obj + 0x68) = D_800F536C_ovl05;
        if (p[0x15] == 0) {
            *(s16*)(obj + 0xA) -= 0x34;
        } else {
            *(s16*)(obj + 0xA) += 0x34;
        }
        obj[0x5C] = 0;
        *(s16*)(obj + 0xE) -= 3;
        DEDUP_CALLEE(obj, 0xF);
        obj[0x60] = 4;
        obj[5] = 2;
    } else if (st == 1) {
        *(u8**)(obj + 0x50) = D_800F5364_ovl05;
        *(u8**)(obj + 0x54) = D_800F5368_ovl05;
        *(u8**)(obj + 0x68) = D_800F5370_ovl05;
        if (p[0x15] == 0) {
            *(s16*)(obj + 0xA) -= 0x12;
        } else {
            *(s16*)(obj + 0xA) += 0x12;
        }
        obj[0x5C] = 3;
        *(s16*)(obj + 0xE) -= 5;
        DEDUP_CALLEE(obj, 0x10);
        obj[0x60] = 2;
        obj[0x8C] = 7;
        obj[5] = 3;
    } else if (st == 2) {
        *(u8**)(obj + 0x50) = D_800F5364_ovl05;
        *(u8**)(obj + 0x54) = D_800F5368_ovl05;
        *(u8**)(obj + 0x68) = D_800F5370_ovl05;
        if (p[0x15] == 0) {
            *(s16*)(obj + 0xA) -= 0x12;
        } else {
            *(s16*)(obj + 0xA) += 0x12;
        }
        obj[0x5C] = 3;
        *(s16*)(obj + 0xE) += 3;
        DEDUP_CALLEE(obj, 0x10);
        obj[0x60] = 2;
        obj[0x8C] = 7;
        obj[5] = 3;
    }
    obj[4] = 1;
    obj[6] = 0;
}
