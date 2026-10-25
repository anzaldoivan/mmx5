/* Shared body (DK-5), from the banked draft of func_800F63CC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* sub;

    DEDUP_CALLEE(obj);
    sub = *(u8**)(obj + 0x7C);
    sub[7]++;
    obj[6]++;
}
