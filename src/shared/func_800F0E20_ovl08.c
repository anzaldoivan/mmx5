/* Shared body (DK-5), from the banked draft of func_800F0E20_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80074E40[];
extern u8 D_800F3D8C_ovl08[];
extern u8 D_800F3D88_ovl08[];
extern void DEDUP_CALLEE(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    *(u8**)(obj + 0x58) = D_80074E40;
    obj[4] = 1;
    obj[3] = 1;
    obj[0x16] = 0;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    if (obj[0x15] == 0) {
        *(u16*)(obj + 0xA) -= 6;
    } else {
        *(u16*)(obj + 0xA) += 6;
    }
    *(u8**)(obj + 0x68) = D_800F3D8C_ovl08;
    *(u8**)(obj + 0x54) = D_800F3D88_ovl08;
    *(u8**)(obj + 0x50) = D_800F3D88_ovl08;
    obj[0x5C] = 1;
    obj[0x60] = 3;
    DEDUP_CALLEE(obj, 5);
}
