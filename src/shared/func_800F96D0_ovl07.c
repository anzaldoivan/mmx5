#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80075D40[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_80101804_ovl07[];
extern u8 D_80101808_ovl07[];
extern u8 D_80101814_ovl07[];
extern u8 D_80101B10_ovl07[];
extern s16 D_80102014_ovl07;
extern s16 D_80102016_ovl07;

void func_800F96D0_ovl07(u8* o) {
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
    if (g_playthrough_state.s[0xC] != 0xC) {
        *(s16*)(o + 0x40) = (*D_80098118 >> 7) + 0xB0;
        *(s16*)(o + 0x42) = 0x7CCC;
        load_palette(0x13C, D_1F800030, 4);
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
    set_animation(o, 2);
    if (g_playthrough_state.s[0xC] != 0xC) {
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

#define SCR D_1F80004C.bytes
extern void (*D_80101C24_ovl07[])(u8*);
extern u8 D_8009A11A;
extern u8 D_80074EE0[];
extern u8 D_80075D40[];
extern void func_800FB3A4_ovl07(u8* a0);
extern void func_800FB5A4_ovl07(u8* a0);

void func_800F991C_ovl07(u8* obj) {
    s32 r;
    u8 t;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    D_80101C24_ovl07[*(signed char*)(obj + 5)](obj);
    func_800FB3A4_ovl07(obj);
    func_800FB5A4_ovl07(obj);
    if (SCR[0x89] == 0) {
        return;
    }
    func_800317B8(obj);
    r = func_80031DD0(obj);
    if (r < 0) {
        D_8009A11A = 1;
        obj[4] = 2;
        obj[5] = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        *(u8**)(obj + 0x58) = D_80074EE0;
        if ((u32)(r - 0x19) < 2) {
            SCR[0x88] = 2;
        } else {
            SCR[0x88] = 0x1E;
        }
        if (r == 4 || r == 0xD || r == 0x23) {
            obj[5] = 0xB;
            obj[6] = 0;
        }
    }
    p = SCR;
    t = p[0x88];
    if (t != 0) {
        p[0x88] = t + 0xFF;
        if (t & 2) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
        if (SCR[0x88] == 0) {
            *(u8**)(obj + 0x58) = D_80075D40;
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    }
}
