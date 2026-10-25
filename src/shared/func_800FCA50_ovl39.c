/* Shared body (DK-5), from the banked draft of func_800FCA50_ovl39 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_CALLEE(u8* arg0, u8 arg1, u8* arg2);

void DEDUP_NAME(u8* arg0) {
    D_1F80004C.bytes[0x88] = 0;
    DEDUP_CALLEE(arg0, D_1F80004C.bytes[0x88], D_1F80004C.bytes);
    *(s16*)(arg0 + 0x7C) = 1;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[6]++;
}
