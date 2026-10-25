/* Shared body (DK-5), from the banked draft of func_800EF4DC_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    s32 v;

    v = 0xFFFF3334;
    obj[6] = 1;
    if (obj[0x15] & 0x40) {
        v = 0xCCCC;
    }
    *(s32*)(obj + 0x20) = v;
    DEDUP_CALLEE(obj);
}
