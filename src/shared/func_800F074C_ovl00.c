/* Shared body (DK-5), from the banked draft of func_800F074C_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* a0) {
    u8* ctx = D_1F80004C.bytes;

    if (ctx[0x90] == 0) {
        switch (*(signed char*)(*(u8**)(ctx + 0x80) + 2)) {
        case 0:
        case 1:
            a0[6] = 1;
            break;
        case 2:
            a0[6] = 3;
            break;
        case 3:
            a0[6] = 5;
            break;
        }
    }
}
