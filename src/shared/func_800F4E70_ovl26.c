/* Shared body (DK-5), from the banked draft of func_800F4E70_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (*(signed char*)(obj + 7) == 2) {
        obj[5] = 7;
        obj[6] = 0;
        *(u16*)(obj + 0xE) = 0x1260;
        if (D_1F80004C.bytes[0x96] != 0) {
            *(u16*)(obj + 0xA) = 0xA10;
            D_1F80004C.bytes[0x96] = 0;
            obj[0x15] = 0;
        } else {
            *(u16*)(obj + 0xA) = 0x910;
            D_1F80004C.bytes[0x96] = 1;
            obj[0x15] = 0x40;
        }
    }
}
