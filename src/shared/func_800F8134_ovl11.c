/* Shared body (DK-5), from the banked draft of func_800F8134_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj);
extern signed char D_800D1CA2;
extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes

void DEDUP_NAME(u8* obj) {
    if (D_800D1CA2 / 2 >= *(signed char*)(obj + 0x5C) && G[0x8E] < 4) {
        obj[5] = 7;
    } else {
        obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
    }
    obj[6] = 0;
    DEDUP_CALLEE(obj);
}
