/* Shared body (DK-5), from the banked draft of func_800F9970_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7C) = 2;
        obj[6]++;
    }
}
