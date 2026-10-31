/* Shared body (DK-5), from the banked draft of func_800F664C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_8009A0A0[];
extern u8 D_80074DA0[];
extern u8 D_80101CE8_ovl04[];
extern u8 D_80101CEC_ovl04[];
extern u8 D_80101CF0_ovl04[];
extern u8 D_80101CF4_ovl04[];
extern u8 D_80101CF8_ovl04[];

void DEDUP_NAME(u8* obj) {
    s32 x;

    obj[4] = 1;
    x = *(s32*)(obj + 8);
    obj[6] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    obj[0x14] = D_8009A0A0[0x14];
    obj[0x93] = 0;
    obj[0x71] = 0;
    switch (*(s8*)(obj + 2)) {
    case 0:
        obj[0x16] = 6;
        obj[0x60] = 6;
        obj[5] = 2;
        obj[0x5C] = 1;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_80101CE8_ovl04;
        *(u8**)(obj + 0x68) = D_80101CEC_ovl04;
        obj[0x15] = (x >= *(s32*)(D_8009A0A0 + 8)) << 6;
        obj[0x91] = 7;
        *(s16*)(obj + 0x88) = 0;
        DEDUP_CALLEE(obj, 10);
        break;
    case 1:
        obj[0x16] = 4;
        obj[5] = 5;
        obj[0x5C] = 4;
        obj[0x60] = 8;
        *(u8**)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = D_80101CF4_ovl04;
        *(u8**)(obj + 0x50) = D_80101CF0_ovl04;
        *(s16*)(obj + 0x88) = 0;
        DEDUP_CALLEE(obj, 9);
        break;
    case 2:
        obj[3] = 0;
        obj[5] = 6;
        obj[0x60] = 0x7F;
        *(u8**)(obj + 0x68) = 0;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x50) = D_80101CF8_ovl04;
        break;
    }
    obj[0x67] = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    obj[0x8E] = 7;
    obj[0x8F] = 0;
    obj[0x90] = 0;
    obj[0x92] = 0;
}
