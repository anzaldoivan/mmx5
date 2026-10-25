/* Shared body (DK-5), from the banked draft of func_800F9F8C_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];

void DEDUP_NAME(u8* arg0) {
    *(u8**)(arg0 + 0x50) = D_800FD57C_ovl01;
    *(u8**)(arg0 + 0x54) = D_800FD578_ovl01;
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
