/* Shared body (DK-5), from the banked draft of func_800F5FA0_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(u8* obj, s32 state);
extern u8 D_80074E40[];
extern u8 D_800FA43C_ovl29[];
extern u8 D_800FA440_ovl29[];
extern u8 D_800FA444_ovl29[];

void DEDUP_NAME(u8* obj) {
    u8 t;

    obj[4] = 1;
    obj[3] = 1;
    *(u8**)(obj + 0x58) = D_80074E40;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(s32*)(obj + 0x28) *= 2;
    *(s32*)(obj + 0x2C) *= 2;
    if (obj[0x15] == 0) {
        *(u16*)(obj + 0xA) += (s8)D_800FA444_ovl29[((s8*)obj)[2] * 2];
    } else {
        *(u16*)(obj + 0xA) -= (s8)D_800FA444_ovl29[((s8*)obj)[2] * 2];
    }
    t = D_800FA444_ovl29[((s8*)obj)[2] * 2 + 1];
    *(s32*)(obj + 0x20) *= 2;
    *(s32*)(obj + 0x24) *= 2;
    obj[0x16] = 0;
    *(u8**)(obj + 0x68) = D_800FA440_ovl29;
    *(u8**)(obj + 0x54) = D_800FA43C_ovl29;
    *(u8**)(obj + 0x50) = D_800FA43C_ovl29;
    obj[0x5C] = 1;
    obj[0x60] = 3;
    *(u16*)(obj + 0xE) += (s8)t;
    DEDUP_CALLEE(obj, 0xC);
}
