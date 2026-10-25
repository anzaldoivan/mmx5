/* Shared body (DK-5), from the banked draft of func_800F8098_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj);

void DEDUP_NAME(u8* obj) {
    u8* p;

    DEDUP_CALLEE(obj);
    if (*(s16*)(obj + 0x7C) == 0) {
        p = D_1F80004C.bytes;
        if ((s8)p[0x8D] != (s8)obj[0x5C]) {
            (*(u8**)(p + 0x80))[5] = 1;
            (*(u8**)(D_1F80004C.bytes + 0x80))[6] = 2;
        }
    } else {
        *(s16*)(obj + 0x7C) -= 1;
    }
    if (*(s8*)(obj + 7) == 0) {
        obj[6]++;
    }
}
