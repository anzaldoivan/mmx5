/* Shared body (DK-5), from the banked draft of func_800F2884_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

void DEDUP_NAME(u8* arg0) {
    s8 temp_a1;

    temp_a1 = *(s8*)(arg0 + 0x45);
    if (temp_a1 == 1) {
        D_1F80004C.bytes[0x82] = temp_a1;
        arg0[6]++;
    }
}
