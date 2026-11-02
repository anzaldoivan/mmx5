/* Shared body (DK-5), from the banked draft of func_800F07C0_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    u8* p;
    s8 st;

    if (D_1F80004C.bytes[0x90] == 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        if (((s8*)p)[2] == 0 && (st = ((s8*)p)[5]) == 3) {
            DEDUP_CALLEE(obj, 1);
            obj[5] = st;
            obj[6] = 0;
        } else {
            *(u16*)(obj + 0xA) =
                *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
            {
                u8* q = *(u8**)(D_1F80004C.bytes + 0x80);
                *(u16*)(obj + 0xE) = *(u16*)(q + 0xE) + *(u16*)(q + 0x8A);
            }
            if ((*(u8**)(D_1F80004C.bytes + 0x80))[0x91] != 0) {
                obj[6] = 1;
            }
        }
    }
}
