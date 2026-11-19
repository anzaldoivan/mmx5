/* Shared body (DK-5), from the banked draft of func_800F5090_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_80044DD0(s32 a0);
extern u8 D_80091C44;

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        set_animation(obj, 0);
        *(s16*)(obj + 0x7E) = 3;
        obj[6] = 6;
        func_80044DD0(2);
    }
}
