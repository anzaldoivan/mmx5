#include "types.h"

extern s32 func_8002D800(u8* a0);
extern int func_8002D760();
extern s16 D_8009A0AE;
extern s16 D_8009A0AA;
extern s8 D_800D1C1D;

void func_80056B28(u8* a0) {
    s32 hit;
    u8 b;

    if (func_8002D800(a0) == 0) {
        b = a0[2];
        if (((s8*)a0)[2] & 0x80) {
            hit = *(s16*)(a0 + 0xE) > D_8009A0AE;
        } else {
            hit = *(s16*)(a0 + 0xA) > D_8009A0AA;
        }
        if (!hit) {
            D_800D1C1D = b & 0x7F;
            func_8002D760(a0);
        }
    } else {
        func_8002D760(a0);
    }
}
