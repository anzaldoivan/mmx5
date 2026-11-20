/* Shared body (DK-5), from the banked draft of func_800F2F40_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void DEDUP_NAME(u8* obj) {
    u8* g = D_1F80004C.bytes;

    if (g[0x85] != 0 && (*(u8**)(g + 0x80))[0x87] == 0) {
        g[0x85] = 0;
        if ((*(u8**)(D_1F80004C.bytes + 0x80))[0x86] == 0) {
            DEDUP_CALLEE(obj);
        }
        obj[4] = 5;
    }
}
