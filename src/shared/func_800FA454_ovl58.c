/* Shared body (DK-5), from the banked draft of func_800FA454_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D53C(void);
extern void func_80013288(s32);
extern u8 D_8009A1F8[];
extern u8* D_800FB5F0_ovl58;

void DEDUP_NAME(u8* arg0) {
    u8* p;

    D_8009A1F8[3] = 0;
    D_8009A1F8[0xAB] = 0;
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xA;
        p[0x36] = 0x11;
        p[2] = 0;
        D_800FB5F0_ovl58 = p;
    }
    func_80013288(8);
    arg0[1]++;
}
