/* Shared body (DK-5), from the banked draft of func_800EFD24_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800F0990_ovl05(u8* obj);
extern u8 D_80075480[];
extern u8 D_8009A0B4;
extern s32 D_800F524C_ovl05;
extern u8 D_800F52C4_ovl05[];
extern u8 D_800F52BC_ovl05[];
extern u8 D_800F52CC_ovl05[];

void DEDUP_NAME(u8* obj) {
    *(u8*)(obj + 0x5C) = 0x1F;
    *(u8*)(obj + 0x60) = 4;
    *(u8**)(obj + 0x58) = D_80075480;
    *(u8*)(obj + 0x61) = 0;
    *(u8*)(obj + 0x14) = D_8009A0B4;
    *(s32**)(obj + 0x30) = &D_800F524C_ovl05;
    *(u8*)(obj + 0x16) = 6;
    *(u8**)(obj + 0x54) = D_800F52C4_ovl05;
    *(u8**)(obj + 0x50) = D_800F52BC_ovl05;
    *(u8*)(obj + 0x67) = 0;
    *(u8**)(obj + 0x68) = D_800F52CC_ovl05;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    func_800171E8(obj, 0);
    func_800F0990_ovl05(obj);
    *(u8*)(obj + 0x67) = 1;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x2000;
    D_1F80004C.bytes[0x84] = 1;
    *(u8*)(obj + 0x5) = 4;
    *(u8*)(obj + 0x6) = 2;
    *(u8*)(obj + 0x4) = 1;
}
