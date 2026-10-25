#include "types.h"
#include "addr.h"

extern s32 func_80028FF0(s32 a, s32 x, s32 y);
extern u8 D_800D1DBC;
extern u16 D_80091D58;

void func_800F9AD4_ovl00(s32 arg0) {
    ((u8*)(D_800D1DBC * 2 + D_80091D58 + (s32)D_1F800004))[0x15] =
        func_80028FF0(1, arg0 + 0x11, 6);
}
