/* Shared body (DK-5), from the banked draft of func_800F2D30_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(u8* a0);

void DEDUP_NAME(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);

    if (((signed char*)p)[4] == 6) {
        obj[4]++;
    }
    obj[0x15] = p[0x15];
    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    DEDUP_CALLEE(obj);
}
