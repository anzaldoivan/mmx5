#include "types.h"
#include "mmx5/globals.h"

void func_800298CC(s16* p) {
    s16* g;
    s32 a;
    s16 d;

    g = D_8009A1F8.h;
    a = (u16)g[5] + (u16)p[0x20];
    p[5] = a;
    d = a - p[0xB];
    p[7] = g[7] + p[0x21];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] + 0x10;
            } else {
                p[5] = a - 0x140;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d < 0x148) {
                p[5] = p[0xB] - 0x10;
            } else {
                p[5] = a + 0x140;
            }
        }
    }
    d = p[7] - p[0xD];
    if (d >= 0) {
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] - 0x140;
            } else {
                p[7] = p[0xD] + 0x10;
            }
        }
    } else {
        d = -d;
        if (d >= 0x10) {
            if (d >= 0x148) {
                p[7] = p[7] + 0x140;
            } else {
                p[7] = p[0xD] - 0x10;
            }
        }
    }
}

#define func_80029304 func_800299CC
#include "shared/func_80029304.c"
#undef func_80029304
