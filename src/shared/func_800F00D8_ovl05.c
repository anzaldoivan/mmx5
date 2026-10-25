/* Shared body (DK-5), from the banked draft of func_800F00D8_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_800F52D0_ovl05[];
extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    *(u8**)(obj + 0x68) = D_800F52D0_ovl05;
    DEDUP_CALLEE(obj, 4);
    obj[0x67] = 1;
    *(s32*)(D_1F80004C.bytes + 0x80) = *(s32*)(obj + 0xC);
    *(s32*)(obj + 0x24) = 0x20000;
    obj[6]++;
}
