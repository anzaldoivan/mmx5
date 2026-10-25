/* Shared body (DK-5), from the banked draft of func_800F56C4_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);
extern u8 D_800FBE00_ovl10[];

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 0x45) == 1) {
        if (obj[0x8E] != 0) {
            obj[0x8E] = 0;
            obj[0x88] = 0;
            obj[5] = D_800FBE00_ovl10[(obj[0x8A] * 2 + obj[0x89]) * 5];
        } else {
            obj[5] =
                D_800FBE00_ovl10[++obj[0x88] + (obj[0x8A] * 2 + obj[0x89]) * 5];
        }
        obj[6] = 0;
    }
}
