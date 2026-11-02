#include "types.h"
#include "addr.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002B5B4(s32);
extern u32* D_80098118;
extern u8 D_80101FB0_ovl07[];

void func_800FF460_ovl07(u8* obj) {
    s32 r;
    s32 r2;

    obj[0] = 0x41;
    *(u16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x8C)] >> 7;
    *(s32*)(obj + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x8C)];
    r = func_8002B5B4(0x8C);
    r2 = func_8002B5B4(0x8C);
    *(u16*)(obj + 0x42) =
        (((r * 4 + 0x18) % 16) | ((((r2 + 6) / 4) + 0x1E0) << 6)) & 0x7FFF;
    *(u8**)(obj + 0x30) = D_80101FB0_ovl07;
    obj[0x14] = 0;
    obj[0x15] = 0;
    if (*(s8*)(obj + 2) == 0) {
        obj[0x54] = 0;
        *(s16*)(obj + 0xA) = 0x1F30;
        *(s16*)(obj + 0xE) = 0xA8;
        obj[0x16] = 7;
        func_800171E8(obj, 0);
    } else {
        func_80016490(5, 0x24, obj);
        obj[0x16] = 6;
        *(s32*)(obj + 0x20) = 0x6C000;
        *(s32*)(obj + 0x24) = 0;
        func_800171E8(obj, 1);
    }
    obj[5] = 0;
    obj[4]++;
}
