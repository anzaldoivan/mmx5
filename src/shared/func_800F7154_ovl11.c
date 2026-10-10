/* Shared body (DK-5), from the banked draft of func_800F7154_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj);
extern signed char D_800D1CA2;
extern u8 D_800F9EEC_ovl11[][5];

#define G (*(u8**)0x1F80004C)

void DEDUP_NAME(u8* obj) {
    DEDUP_CALLEE(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (D_800D1CA2 / 2 >= *(signed char*)(obj + 0x5C) && G[0x8E] < 4) {
            obj[5] = 7;
        } else {
            obj[5] = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        }
        obj[6] = 0;
    }
}
