/* Shared body (DK-5), from the banked draft of func_800F7234_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_80074DA0[];
extern u8 D_800FBF3C_ovl10[];

void DEDUP_NAME(u8* obj) {
    obj[4] = 0xB;
    obj[3] = 1;
    obj[0x16] = 6;
    *(u8**)(obj + 0x58) = D_80074DA0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(u8**)(obj + 0x50) = D_800FBF3C_ovl10;
    obj[0x5C] = 4;
    obj[0x60] = 4;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    DEDUP_CALLEE(obj, 0xE);
}
