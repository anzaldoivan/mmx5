/* Shared body (DK-5), from the banked draft of func_800EF044_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800FA614_ovl09[];
extern u8 D_800FA618_ovl09[];
extern u8 D_800FA61C_ovl09[];
extern u8 D_800FA738_ovl09[];

void DEDUP_NAME(u8* obj) {
    s32 two = 2;
    s32 one = 1;
    s32 v;

    obj[4] = one;
    obj[6] = 0;
    obj[0x14] = D_8009A0B4;
    v = 6;
    obj[0x16] = v;
    v = 3;
    obj[0x5C] = v;
    obj[0x15] = 0;
    obj[0x61] = 0;
    obj[0x60] = two;
    *(u8**)(obj + 0x30) = D_800FA738_ovl09;
    if (*(s8*)(obj + 2) != 0) {
        *(u8**)(obj + 0x68) = D_800FA61C_ovl09;
        *(u8**)(obj + 0x58) = D_800750C0;
        obj[5] = two;
        *(u8**)(obj + 0x50) = D_800FA614_ovl09;
        *(u8**)(obj + 0x54) = D_800FA618_ovl09;
        obj[0x94] = 0;
        obj[0x95] = one;
    } else {
        obj[5] = 5;
        *(u8**)(obj + 0x58) = 0;
        *(u8**)(obj + 0x50) = 0;
        *(u8**)(obj + 0x54) = 0;
        obj[0x94] = one;
        obj[7] = 0;
    }
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    *(s16*)(obj + 0x84) = 0;
    obj[0x93] = 0x20;
    obj[0x90] = 0;
    obj[0x91] = 0;
    obj[0x92] = 0;
    DEDUP_CALLEE(obj, 0);
}
