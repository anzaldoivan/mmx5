#include "types.h"

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

extern s32 func_80028FF0(s32 a, s32 x, s32 y);

s32 func_80030918(Obj80030820* obj) {
    u8* p = obj->unk68;
    u32 a = obj->unkA << 16;
    u32 b = (u16)(obj->unkE + (signed char)p[1] + p[3]) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    s32 v;

    ret = func_80028FF0(obj->unk14, x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        v = D_1F80000C[(*(u16*)(D_1F800008 + ret * 512 + sy * 32 + sx * 2) &
                        0x3FFF) *
                       4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
