/* Shared body (DK-5), from the banked draft of func_80040B6C by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(void);

s32 DEDUP_NAME(u8* arg0) {
    u32 flag;
    u8 cnt;

    flag = arg0[0x80];
    cnt = --arg0[0xE8];
    flag >>= 7;
    if (cnt == 0) {
        flag = 1;
    }
    if (flag != 0) {
        DEDUP_CALLEE();
        return 1;
    }
    return 0;
}
