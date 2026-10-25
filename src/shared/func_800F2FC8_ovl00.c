/* Shared body (DK-5), from the banked draft of func_800F2FC8_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_CALLEE(void);

void DEDUP_NAME(u8* arg0) {
    if (D_1F80004C.bytes[0x88] != 0) {
        arg0[2] = 0;
        DEDUP_CALLEE();
        D_1F80004C.bytes[0x88] = 0;
    }
}
