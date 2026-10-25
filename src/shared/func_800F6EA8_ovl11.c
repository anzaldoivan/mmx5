/* Shared body (DK-5), from the banked draft of func_800F6EA8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern void DEDUP_CALLEE(s32 a0);

void DEDUP_NAME(u8* obj) {
    if (D_80091C44 == 0) {
        DEDUP_CALLEE(0);
        *(s16*)(obj + 0x7E) = 10;
        obj[6]++;
    }
}
