/* Shared body (DK-5), from the banked draft of func_800EF93C_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8002D800(u8* a0);

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (func_8002D800(obj) != 0 ||
        (((s32(*)())func_8002D9EC)(obj, 0x30, 0x10), *(s8*)(obj + 0x46) == 0)) {
        obj[4]++;
    }
}
