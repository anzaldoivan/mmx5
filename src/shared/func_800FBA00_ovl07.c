/* Shared body (DK-5), from the banked draft of func_800FBA00_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80091C44;

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        set_animation(obj, 0);
        D_1F80004C.bytes[0x92] = 0;
        *(s16*)(obj + 0x7C) = 0x50;
        *(s16*)(obj + 0x7E) = 0x17;
        obj[6]++;
    }
}
