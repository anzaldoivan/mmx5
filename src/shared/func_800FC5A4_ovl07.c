/* Shared body (DK-5), from the banked draft of func_800FC5A4_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);
extern u8 D_80101808_ovl07[];
extern u8 D_80101804_ovl07[];

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(u8**)(obj + 0x54) = D_80101808_ovl07;
        *(u8**)(obj + 0x50) = D_80101804_ovl07;
        DEDUP_CALLEE(obj);
    }
}
