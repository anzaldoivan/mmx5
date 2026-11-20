/* Shared body (DK-5), from the banked draft of func_800F620C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_80076060[];

void DEDUP_NAME(u8* obj) {
    *(u8**)(obj + 0x58) = D_80076060;
    DEDUP_CALLEE(obj, 0);
    obj[5] = 4;
    obj[6] = 2;
}
