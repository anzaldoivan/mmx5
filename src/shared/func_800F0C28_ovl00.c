/* Shared body (DK-5), from the banked draft of func_800F0C28_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

#include "addr.h"

void DEDUP_NAME(u8* a0) {
    u8* s = D_1F80004C.bytes;

    if (s[0x90] == 0 && s[0x84] == 0) {
        s[0x90] = 1;
        a0[5] = 4;
        a0[6] = 0;
        if (*(u32*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x90) & 0xFF00FF00) {
            a0[4] = 5;
        }
    }
}
