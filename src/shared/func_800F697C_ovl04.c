/* Shared body (DK-5), from the banked draft of func_800F697C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(u8* obj);
extern void (*D_80101D40_ovl04[])(u8*);

void DEDUP_NAME(u8* obj) {
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    DEDUP_CALLEE(obj);
    D_80101D40_ovl04[*(s8*)(obj + 4)](obj);
    obj[0x71] = 0;
}
