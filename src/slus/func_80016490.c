#include "types.h"

extern s32 func_80016850(s32, s32, s32);
extern s32 func_8001657C(s32, s32, s32);
extern s8 D_80093E60[];
extern u8* D_8009A730[];
extern u8* D_8009A770[];
extern u8* D_800E6B84;
extern u8 D_800703C0[];

s32 func_80016490(u8 arg0, u8 arg1, s32 arg2) {
    u8* p;
    u8 b;
    u8 v;
    s32 c;

    if (D_80093E60[arg0 & 0x7F] == -1) {
        return -1;
    }
    if ((s32)((u8)(((u32)D_8009A730[arg0 & 0xF] -
                    (u32)D_8009A770[arg0 & 0xF]) >>
                   2) -
              1) < arg1) {
        return -2;
    }
    D_800E6B84 = p = D_8009A770[arg0 & 0xF] + arg1 * 4;
    if (*(s32*)p == 0) {
        return -5;
    }
    b = *p;
    v = D_800703C0[b >> 6];
    c = b & 0x3F;
    if (v == 0) {
        return func_8001657C(arg0, c, arg2);
    }
    return func_80016850(v, c, arg2);
}
