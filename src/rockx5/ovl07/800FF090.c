#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern s32 func_8002B5B4(s32);
extern u8 D_800750C0[];
extern u32* D_80098118;
extern u8 D_8009A0B4;
extern u8 D_80101F2C_ovl07[];
extern u8 D_80101F5C_ovl07[];
extern u8 D_80101F60_ovl07[];
extern u8 D_80101F64_ovl07[];
extern u8 D_80101F68_ovl07[];

void func_800FF090_ovl07(u8* obj) {
    s32* t;
    s32 r;
    s32 v;

    obj[0] = 0x41;
    obj[0x15] = 0;
    *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x8C)] >> 7;
    r = func_8002B5B4(0x8C);
    t = D_1F800020.s32s;
    *(s32*)(obj + 0x3C) = (s32)t + t[r];
    r = func_8002B5B4(0x8C);
    v = func_8002B5B4(0x8C);
    *(s16*)(obj + 0x42) = ((r * 4 + 0x18) % 16) | (((v + 6) / 4 + 0x1E0) << 6);
    obj[0x75] = 1;
    obj[0x76] = 0;
    obj[0x67] = 0;
    *(u8**)(obj + 0x30) = D_80101F2C_ovl07;
    obj[0x14] = D_8009A0B4;
    obj[0x16] = 6;
    obj[0x60] = 0x7F;
    *(s32*)(obj + 0x20) = 0;
    obj[0x66] = 1;
    if (*(s8*)(obj + 2) == 0) {
        set_animation(obj, 0);
        obj[0x5C] = 4;
        *(u8**)(obj + 0x54) = D_80101F5C_ovl07;
        *(u8**)(obj + 0x68) = D_80101F60_ovl07;
    } else {
        set_animation(obj, 1);
        obj[0x5C] = 1;
        *(u8**)(obj + 0x54) = D_80101F64_ovl07;
        *(u8**)(obj + 0x68) = D_80101F68_ovl07;
    }
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    obj[0x15] = 0;
    obj[0x65] = 0;
    *(s32*)(obj + 0x50) = 0;
    obj[4] = 1;
}

extern s32 func_80032F70(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8003240C(u8* a0);
extern u8 D_80101F54_ovl07[];
extern u8 D_80101F58_ovl07[];

void func_800FF228_ovl07(u8* obj) {
    s8 r;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    animate_object(obj);
    r = func_80032F70(obj);
    if (r < 0) {
        if (*(s8*)(obj + 2) == 0) {
            func_8004D4F4(4, D_80101F54_ovl07, obj);
            func_8004FD90(obj, 1, 0x10, 0x20);
        } else {
            func_8004D4F4(4, D_80101F58_ovl07, obj);
            func_8004FD90(obj, 1, 8, 0x20);
        }
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s16*)(obj + 0x7E) = 5;
        obj[3] = 0;
        obj[4] = 3;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        return;
    }
    if (r > 0) {
        *(u16*)(obj + 0x42) |= 0x8000;
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    func_8003240C(obj);
    if (is_off_screen(obj, 0x40, 0x40) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 2;
}
