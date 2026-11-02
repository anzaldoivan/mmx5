/* Shared body (DK-5), from the banked draft of func_800FB348_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(void);
extern u8 D_800FD630_ovl01[];

void DEDUP_NAME(u8* arg0) {
    s32 i;

    arg0[0x91] = 0;
    for (i = 0; i < 3; i++) {
        if ((u32)(DEDUP_CALLEE() & 0xF) <
            D_800FD630_ovl01[i + arg0[0x89] * 2]) {
            break;
        }
    }
    switch (arg0[0x89]) {
    case 0:
        arg0[0x90] = i;
        break;
    case 1:
        arg0[0x90] = 2;
        break;
    case 2:
        arg0[0x90] = i + 3;
        break;
    }
}
