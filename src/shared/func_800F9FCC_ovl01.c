/* Shared body (DK-5), from the banked draft of func_800F9FCC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        set_animation(obj, 0);
        func_800FB308_ovl01(obj);
        obj[5] = 3;
        obj[6] = 0;
    }
}
