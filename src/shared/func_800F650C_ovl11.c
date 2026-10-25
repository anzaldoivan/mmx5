/* Shared body (DK-5), from the banked draft of func_800F650C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 DEDUP_CALLEE(void);
extern signed char D_800D1CA2;
extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* obj) {
    u32 r = DEDUP_CALLEE() & 0xF;

    if (D_800D1CA2 / 2 < *(signed char*)(obj + 0x5C)) {
        if (r < 7) {
            G[0x8E] = 0;
        } else if (r < 12) {
            G[0x8E] = 1;
        } else if (r < 14) {
            G[0x8E] = 2;
        } else {
            G[0x8E] = 3;
        }
    } else {
        if (r < 8) {
            G[0x8E] = 4;
        } else if (r < 11) {
            G[0x8E] = 5;
        } else if (r < 14) {
            G[0x8E] = 6;
        } else {
            G[0x8E] = 7;
        }
    }
    G[0x8F] = 0;
    obj[5] = D_800F9EEC_ovl11[0][G[0x8F] + G[0x8E] * 5];
    obj[6] = 0;
}
