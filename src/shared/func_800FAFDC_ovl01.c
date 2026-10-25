/* Shared body (DK-5), from the banked draft of func_800FAFDC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DF54(u8* a0);
extern u8 D_800FD604_ovl01[];
extern u8 D_800FD600_ovl01[];
extern u8 D_800FD608_ovl01[];

void DEDUP_NAME(u8* arg0) {
    func_800171E8(arg0, 3);
    *(u8**)(arg0 + 0x50) = D_800FD604_ovl01;
    *(u8**)(arg0 + 0x54) = D_800FD600_ovl01;
    *(s32*)(arg0 + 0x24) = 0x20000;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0x1000;
    *(u8**)(arg0 + 0x68) = D_800FD608_ovl01;
    func_8002DF54(arg0);
    arg0[6] = 1;
}
