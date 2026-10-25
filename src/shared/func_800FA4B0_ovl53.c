/* Shared body (DK-5), from the banked draft of func_800FA4B0_ovl53 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002D53C(void);
extern void func_80013288(s32);
extern u8* D_800FB59C_ovl53;

void DEDUP_NAME(u8* arg0) {
    func_80013288(8);
    D_800FB59C_ovl53 = func_8002D53C();
    if (D_800FB59C_ovl53 != 0) {
        D_800FB59C_ovl53[0] = 1;
        D_800FB59C_ovl53[1] = 0xA;
        D_800FB59C_ovl53[0x36] = 0;
        D_800FB59C_ovl53[2] = 2;
    }
    arg0[1]++;
}
