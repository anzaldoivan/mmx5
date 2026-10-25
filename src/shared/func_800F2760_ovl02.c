/* Shared body (DK-5), from the banked draft of func_800F2760_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(void* obj, s32 anim);

void DEDUP_NAME(u8* arg0) {
    D_1F80004C.bytes[0x82] = 0;
    DEDUP_CALLEE(arg0, 0);
    *(s16*)(arg0 + 0x7C) = 0x5A;
    arg0[6]++;
}
