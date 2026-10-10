#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 padC[2];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ signed char unk14;
} Obj80030A0C;

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

extern s32 func_80028FF0(s32 a, s32 x, s32 y);

s32 func_80030A0C(Obj80030A0C* obj) {
    u32 a = obj->unkA << 16;
    u32 b = obj->unkE << 16;
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
