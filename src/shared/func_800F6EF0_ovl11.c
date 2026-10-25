/* Shared body (DK-5), from the banked draft of func_800F6EF0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE();
extern signed char D_800D1C0C;
extern u8 D_8009A240;

void DEDUP_NAME(u8* obj) {
    if (DEDUP_CALLEE() == 0) {
        if (D_800D1C0C == 12 && *(s16*)(obj + 0x7E) != 0) {
            *(s16*)(obj + 0x7E) -= 1;
        } else {
            D_8009A240 = 2;
            *(s16*)(obj + 0x7C) = 2;
            obj[6]++;
        }
    }
}
