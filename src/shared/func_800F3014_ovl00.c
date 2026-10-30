/* Shared body (DK-5), from the banked draft of func_800F3014_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_80074DA0[];
extern u8 D_800FADA0_ovl00[];
extern u8 D_800FADA8_ovl00[];
extern u8 D_800FADAC_ovl00[];
extern u8 D_800FADB0_ovl00[];
extern u8 D_800FADB4_ovl00[];

void DEDUP_NAME(u8* obj) {
    u8* p;
    s16 e;

    obj[3] = 1;
    p = *(u8**)(obj + 0x7C);
    obj[0x8C] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(u8**)(obj + 0x58) = D_80074DA0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    obj[0x8D] = p[1];
    switch (*(s8*)(obj + 2)) {
    case 0:
        obj[0x5C] = 2;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADAC_ovl00;
        *(u8**)(obj + 0x54) = D_800FADB0_ovl00;
        *(u8**)(obj + 0x68) = D_800FADB4_ovl00;
        DEDUP_CALLEE(obj, 0xB);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x12;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x12;
        }
        e = *(s16*)(p + 0xE) - 0x17;
        obj[5] = 0;
        *(s16*)(obj + 0xE) = e;
        break;
    case 1:
        obj[0x5C] = 2;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADAC_ovl00;
        *(u8**)(obj + 0x54) = D_800FADB0_ovl00;
        *(u8**)(obj + 0x68) = D_800FADB4_ovl00;
        DEDUP_CALLEE(obj, 0xB);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x10;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x10;
        }
        e = *(s16*)(p + 0xE) - 7;
        obj[5] = 0;
        *(s16*)(obj + 0xE) = e;
        break;
    case 2:
        obj[0x5C] = 1;
        obj[0x60] = 3;
        *(u8**)(obj + 0x50) = D_800FADA0_ovl00;
        *(u8**)(obj + 0x54) = 0;
        *(u8**)(obj + 0x68) = D_800FADA8_ovl00;
        DEDUP_CALLEE(obj, 7);
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) + 0x10;
        } else {
            *(s16*)(obj + 0xA) = *(s16*)(p + 0xA) - 0x10;
        }
        e = *(s16*)(p + 0xE) - 0x18;
        obj[5] = 2;
        *(s16*)(obj + 0xE) = e;
        break;
    }
    obj[4]++;
}
