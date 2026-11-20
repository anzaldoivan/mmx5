/* Shared body (DK-5), from the banked draft of func_800F36FC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"

extern s16 D_8009A0AE;

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (D_8009A0AE >= *(s16*)(obj + 0xE)) {
        obj[5] = 1;
        obj[6] = 0;
    }
}
