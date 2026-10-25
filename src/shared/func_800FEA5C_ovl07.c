/* Shared body (DK-5), from the banked draft of func_800FEA5C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (*(s8*)(obj + 0x45) == 6) {
        obj[4] = 2;
        return;
    }
    if (*(s8*)(obj + 2) == 5) {
        *(u16*)(obj + 0xA) -= 0x10;
    } else {
        *(u16*)(obj + 0xA) += 0x10;
    }
    DEDUP_CALLEE(obj);
}
