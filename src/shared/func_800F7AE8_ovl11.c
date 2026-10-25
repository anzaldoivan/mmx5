/* Shared body (DK-5), from the banked draft of func_800F7AE8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj);
extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        obj[6] = 0;
    }
}
