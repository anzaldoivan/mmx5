#include "types.h"
#include "addr.h"

extern s32 func_80028FF0(s32 a, s32 x, s32 y);

s32 func_800306E0(Obj80030820* obj) {
    u8* p = obj->unk68;
    s32 d;
    s16 a;
    s16 b;
    s32 x;
    s32 y;
    s32 sx;
    s32 sy;
    s32 ret;
    s32 v;

    if (((signed char*)obj)[2] != 0) {
        d = 8;
    } else {
        d = 14;
    }
    a = obj->unkA;
    b = obj->unkE + (signed char)p[1] - p[3] - d;
    x = a >> 8;
    y = b >> 8;
    sx = (u32)(a & 0xF0) >> 4;
    sy = (u32)(b & 0xF0) >> 4;

    ret = func_80028FF0(obj->unk14, x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        *(s16*)((u8*)obj + 0x6C) = a & 0xF;
        *(s16*)((u8*)obj + 0x6E) = b & 0xF;
        v = D_1F80000C[(*(u16*)(D_1F800008 + ret * 512 + sy * 32 + sx * 2) &
                        0x3FFF) *
                       4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
