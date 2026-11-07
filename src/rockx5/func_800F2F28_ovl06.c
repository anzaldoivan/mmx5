#include "types.h"

extern u8 D_80092090[];

void func_800F2F28_ovl06(u8* obj) {
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 tx;
    s32 ty;
    s32 found;
    u8* t;
    u8* p;

    found = 0;
    for (p = D_80092090; p < D_80092090 + 0x1D40; p += 0x9C) {
        if (((s8*)p)[0] != 0 && ((s8*)p)[3] != 0 && ((s8*)p)[0x7A] == 0) {
            t = *(u8**)(obj + 0x8C);
            if (t != 0) {
                x = *(s32*)(obj + 8);
                dx = x - *(s32*)(p + 8) < 0 ? *(s32*)(p + 8) - x
                                            : x - *(s32*)(p + 8);
                y = *(s32*)(obj + 0xC);
                dy = y - *(s32*)(p + 0xC) < 0 ? *(s32*)(p + 0xC) - y
                                              : y - *(s32*)(p + 0xC);
                tx = x - *(s32*)(t + 8) < 0 ? *(s32*)(t + 8) - x
                                            : x - *(s32*)(t + 8);
                ty = y - *(s32*)(t + 0xC) < 0 ? *(s32*)(t + 0xC) - y
                                              : y - *(s32*)(t + 0xC);
                dx += dy;
                tx += ty;
                if (tx > dx) {
                    *(u8**)(obj + 0x8C) = p;
                }
            } else {
                *(u8**)(obj + 0x8C) = p;
            }
            found = 1;
        }
    }
    if (found == 0) {
        *(u8**)(obj + 0x8C) = 0;
    }
}
