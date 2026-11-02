#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_800750C0[];
extern u8 D_8009A0B4;
extern u8 D_800FB410_ovl09[];

void func_800F7B58_ovl09(u8* obj) {
    s8 kind;
    u8 b;
    s32 x;
    s32 y;

    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x61] = 0;
    b = D_8009A0B4;
    *(u8**)(obj + 0x30) = D_800FB410_ovl09;
    kind = obj[2];
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x67] = 0;
    x = *(s32*)(obj + 0x8);
    y = *(s32*)(obj + 0xC);
    obj[0x16] = 4;
    obj[0x62] = 0;
    obj[0x15] = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x68) = 0;
    *(s32*)(obj + 0x54) = 0;
    obj[0x14] = b;
    *(s32*)(obj + 0x18) = x;
    *(s32*)(obj + 0x1C) = y;
    switch (kind) {
    case 0:
        func_8002C338(0x13C, D_1F800030, 4);
        obj[3] = 0;
        obj[0x5C] = 0;
        obj[0x60] = 0;
        obj[0x47] = 0;
        *(s32*)(obj + 0x54) = 0;
        D_1F80004C.bytes[0x84] = 0;
        D_1F80004C.bytes[0x85] = 0;
        D_1F80004C.bytes[0x86] = 0;
        obj[4] = 1;
        obj[5] = 0;
        break;
    case 1:
        D_1F80004C.bytes[0x86] = 0;
        obj[3] = kind;
        obj[0x60] = 8;
        func_800171E8(obj, 1);
        obj[4] = 3;
        obj[5] = 2;
        break;
    case 2:
        D_1F80004C.bytes[0x86] = 0;
        obj[3] = 1;
        obj[0x60] = 8;
        func_800171E8(obj, 1);
        obj[4] = 3;
        obj[5] = 2;
        break;
    case 3:
        D_1F80004C.bytes[0x86] = 0;
        obj[3] = 1;
        obj[0x60] = 8;
        func_800171E8(obj, 1);
        obj[4] = kind;
        obj[5] = 2;
        break;
    }
    obj[6] = 0;
}
