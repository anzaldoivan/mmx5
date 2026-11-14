#include "types.h"

extern D1C00 D_800D1C00;

void func_80039BF0(u8* p) {
    s8 v;
    s32 f;
    s8 i;

    if (*(s8*)(p + 0xF0) == 0) {
        v = *(s8*)(p + 5);
        if (v != 0) {
            if (v != 1) {
                f = p[0xFB];
                if ((u8)f == 0x9F) {
                    p[0xFB] = f & 0x7F;
                    i = *(s8*)(p + 2);
                    *(s8*)(p + 0x14B) = -1;
                    *(s32*)(p + 0x14C) = 0;
                    if (i != 0) {
                        p[0x7A] = 1;
                        p[0x5C] = D_800D1C00.unk47[i];
                    }
                } else if (f & 0x80) {
                    p[0xFB] = f & 0x7F;
                    p[0x14B] = 1;
                    p[0x154] = 0x4B;
                }
            }
        }
    }
}
