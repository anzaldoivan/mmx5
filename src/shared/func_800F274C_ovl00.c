/* Shared body (DK-5), from the banked draft of func_800F274C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    D_1F80004C.s8s[0x89] = 1;
    D_1F80004C.s8s[0x80] = -0x40;
    D_1F80004C.s8s[0x81] = 4;
    D_1F80004C.s8s[0x82] = 0x18;
    D_1F80004C.s8s[0x83] = 0x10;
    DEDUP_CALLEE(obj, 3);
    obj[6]++;
}
