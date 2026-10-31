/* Shared body (DK-5), from the banked draft of func_800EF48C_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002DF78(void);
extern u8 D_800F20BC_ovl12[];
extern u8 D_800F20C0_ovl12[];
extern u8 D_80074EE0[];

void DEDUP_NAME(u8* obj) {
    u8* parent = *(u8**)(obj + 0x7C);
    s32 t;

    *(u16*)(obj + 0x40) = *(u16*)(parent + 0x40);
    *(u16*)(obj + 0x42) = *(u16*)(parent + 0x42) & 0x7FFF;
    *(s32*)(obj + 0x30) = *(s32*)(parent + 0x30);
    *(s32*)(obj + 0x3C) = *(s32*)(parent + 0x3C);
    obj[0x16] = 1;
    obj[0x14] = 0;
    t = parent[0x15];
    obj[0x67] = 0;
    obj[0x3] = 0;
    *(s32*)(obj + 0x68) = 0;
    *(u8**)(obj + 0x50) = D_800F20BC_ovl12;
    *(u8**)(obj + 0x54) = D_800F20C0_ovl12;
    *(u8**)(obj + 0x58) = D_80074EE0;
    obj[0x15] = t;
    func_800171E8(obj, 0xD);
    if (obj[0x15] == 0) {
        *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) - 0x10;
        *(s32*)(obj + 0x20) = 0xFFFB0000;
    } else {
        *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + 0x10;
        *(s32*)(obj + 0x20) = 0x50000;
    }
    if (func_8002DF78() & 1) {
        *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x7C) + 0xE) - 6;
        obj[0x6] = 0;
    } else {
        *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x7C) + 0xE) + 6;
        obj[0x6] = 1;
    }
    obj[0x5C] = 1;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x60] = 6;
    obj[0x5] = 0;
    obj[0x4]++;
}
