/* Shared body (DK-5), from the banked draft of func_800F166C_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    u8* parent;

    DEDUP_CALLEE(obj, 10);
    parent = *(u8**)(obj + 0x50);
    *(s32*)(obj + 0x8) = *(s32*)(parent + 0x8);
    *(s32*)(obj + 0xC) = *(s32*)(parent + 0xC);
    obj[0x16] = parent[0x16];
    if (obj[0x15] != 0) {
        *(s16*)(obj + 0xA) += 3;
    } else {
        *(s16*)(obj + 0xA) -= 3;
    }
    obj[4] = 1;
}
