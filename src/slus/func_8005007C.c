#include "types.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_800171E8(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8002D89C(u8*);
extern s32 D_8007B724;

void func_8005007C(u8* arg0) {
    u8* s;
    s32 x;

    FX(arg0, u8, 0x3) = 1;
    x = FX(arg0, signed char, 0x2) + 4;
    FX(arg0, s32, 0x38) = 0;
    s = D_1F80001C.bytes;
    FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x8);
    FX(arg0, void*, 0x30) = &D_8007B724;
    FX(arg0, s16, 0x40) = 0;
    FX(arg0, s16, 0x42) = (x % 16) | ((x / 16 + 0x1E0) << 6);
    func_800171E8(arg0, 0);
    if (FX(arg0, u8, 0x5C) != 0xFF) {
        func_80016490(0, FX(arg0, u8, 0x5C), arg0);
    }
    FX(arg0, u8, 0x4)++;
    func_8002D89C(arg0);
}
