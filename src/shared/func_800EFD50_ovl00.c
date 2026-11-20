/* Shared body (DK-5), from the banked draft of func_800EFD50_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "addr.h"

void DEDUP_NAME(void) {
    u8* p = D_1F80004C.bytes;

    if (p[0x84] != 0) {
        (*(u8**)(p + 0x80))[0x85] = 0;
    }
    DEDUP_CALLEE();
}
