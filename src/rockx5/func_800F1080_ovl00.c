#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u16 D_8009A206;
extern u8 D_800FA984_ovl00[];

void func_800F1080_ovl00(u8* obj) {
    s32 a;
    s32 b;

    obj[0] = 0x41;
    *(s16*)(obj + 0x40) = D_80098118[func_8002B5B4(0x83)] >> 7;
    *(s32*)(obj + 0x3C) =
        (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(0x83)];
    a = func_8002B5B4(0x83);
    b = func_8002B5B4(0x83);
    *(s16*)(obj + 0x42) = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    *(u8**)(obj + 0x30) = D_800FA984_ovl00;
    *(s8*)(obj + 0x14) = -1;
    obj[0x15] = 0;
    *(u16*)(obj + 0xE) -= D_8009A206;
    *(u16*)(obj + 0x54) = *(u16*)(obj + 0xA);
    if (((s8*)obj)[2] == 0) {
        func_800171E8(obj, 0);
    } else {
        func_800171E8(obj, 1);
    }
    obj[0x16] = 0;
    obj[4]++;
}
