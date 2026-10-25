/* Shared body (DK-5), from the banked draft of func_800F5D5C_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);
extern u8 D_80076060[];

void DEDUP_NAME(u8* obj) {
    s8 v;

    DEDUP_CALLEE(obj);
    v = ((s8*)obj)[0x45];
    if (v == 1) {
        *(u8**)(obj + 0x58) = D_80076060;
        obj[5] = 7;
        obj[6] = v;
    }
}
