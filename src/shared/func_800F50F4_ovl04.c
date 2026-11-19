/* Shared body (DK-5), from the banked draft of func_800F50F4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        obj[5]++;
        obj[6] = 0;
        *(s16*)(obj + 0x7C) = 3;
        func_80044DD0(4);
        set_animation(obj, 2);
    }
}
