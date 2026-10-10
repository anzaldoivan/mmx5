/* Shared body (DK-5), from the banked draft of func_800EFC34_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern u8 D_800D1C24;

extern void func_80044DD0(s32 a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* arg0) {
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        arg0[6]++;
        D_800D1C24 = 1;
    }
    func_8002D9EC(arg0, 0x40, 0x40);
}
