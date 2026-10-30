/* Shared body (DK-5), from the banked draft of func_800F96D0_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_80075D40[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern s8 D_800D1C00[];
extern u8 D_80101804_ovl07[];
extern u8 D_80101808_ovl07[];
extern u8 D_80101814_ovl07[];
extern u8 D_80101B10_ovl07[];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void DEDUP_NAME(u8* o) {
    u8* p;
    s32 t;
    s32 a;
    s32 b;
    s32 n;

    D_1F80004C.bytes[0x8A] = 0x30;
    o[0x60] = 4;
    o[0x5C] = 0;
    o[0x61] = 0;
    *(u8**)(o + 0x58) = D_80075D40;
    if (D_800D1C00[0xC] != 0xC) {
        *(s16*)(o + 0x40) = (*D_80098118 >> 7) + 0xB0;
        *(s16*)(o + 0x42) = 0x7CCC;
        func_8002C338(0x13C, D_1F800030, 4);
    } else {
        *(s16*)(o + 0x40) = (*D_80098118 >> 7) + 0x210;
        p = D_1F80009C;
        n = *(s32*)p;
        *(s16*)(o + 0x42) = 0x7CCC;
        *(u8**)(o + 0x3C) = p + n;
    }
    t = D_8009A0B4;
    *(s32*)(o + 0x20) = 0;
    *(u8**)(o + 0x30) = D_80101B10_ovl07;
    o[0x16] = 5;
    *(u8**)(o + 0x54) = D_80101808_ovl07;
    *(u8**)(o + 0x50) = D_80101804_ovl07;
    a = *(s32*)(o + 0x8);
    b = *(s32*)(o + 0xC);
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x67] = 0;
    *(u8**)(o + 0x68) = D_80101814_ovl07;
    o[0x15] = 0;
    o[0x14] = t;
    *(s32*)(o + 0x18) = a;
    *(s32*)(o + 0x1C) = b;
    D_1F80004C.bytes[0x89] = 0;
    D_1F80004C.bytes[0x8B] = 0;
    D_1F80004C.bytes[0x8C] = 0;
    D_1F80004C.bytes[0x8D] = 0;
    D_1F80004C.bytes[0x8E] = 2;
    D_1F80004C.bytes[0x8F] = 0;
    D_1F80004C.bytes[0x88] = 0;
    D_1F80004C.bytes[0x96] = 0;
    D_1F80004C.bytes[0x95] = 0;
    D_1F80004C.bytes[0x97] = 0;
    D_1F80004C.bytes[0x93] = 0xFF;
    D_1F80004C.bytes[0x94] = 0xFF;
    o[0x3] = 0;
    o[0x65] = 0;
    func_800171E8(o, 2);
    if (D_800D1C00[0xC] != 0xC) {
        D_80102014_ovl07 = 0;
        D_80102016_ovl07 = 0;
    } else {
        D_80102014_ovl07 = -0x1B60;
        D_80102016_ovl07 = -0x440;
    }
    o[0x4] = 1;
    o[0x5] = 2;
    o[0x6] = 0;
}
