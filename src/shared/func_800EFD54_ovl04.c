/* Shared body (DK-5), from the banked draft of func_800EFD54_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(void);
extern s8 D_8009A23C;
extern s8 D_800D1C26;

void DEDUP_NAME(u8* arg0) {
    if (D_800D1C26 & 1) {
        arg0[6]++;
        D_8009A23C = 0;
        DEDUP_CALLEE();
    }
}
