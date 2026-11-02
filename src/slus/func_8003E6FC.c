#include "types.h"

extern s16 D_800748F4[];
extern s16 D_80074960[];
extern u8 D_800D1C4A;

s16 func_8003E6FC(u8* arg0, s8 arg1) {
    s16 v;
    s32 n;

    if (*(s8*)(arg0 + 2) != 0) {
        if (*(s32*)(arg0 + 0xFC) & 0x20) {
            return D_80074960[arg1] * 3;
        }
        if (D_800D1C4A & 0x10) {
            return D_80074960[arg1] * 4;
        }
        return D_80074960[arg1] * 6;
    }
    v = D_800748F4[arg1] * 6;
    if (v == 0) {
        return 0;
    }
    if (*(s32*)(arg0 + 0xFC) & 0x20) {
        v = v / 2;
    } else {
        n = arg0[0xFA];
        if (n < 5) {
            if (n != 0) {
                v = v * 2 / 3;
            }
        }
    }
    if (v == 0) {
        v = 1;
    }
    return v;
}
