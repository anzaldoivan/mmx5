/* Shared body (DK-5), from the banked draft of func_800F5CB8_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* sub = *(u8**)(obj + 0x7C);

    sub[7]++;
    DEDUP_CALLEE(obj);
    obj[6]++;
}
