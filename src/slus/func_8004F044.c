#include "types.h"

extern u16 D_8007B5AC[][2];
extern s16 D_800D1C0A;

void func_8004F044(u8* arg0) {
    s32 i;

    i = ((s8*)arg0)[2] >> 4;
    if (D_800D1C0A == 0) {
        *(s16*)(arg0 + 0xA) = 0x28;
    } else {
        *(s16*)(arg0 + 0xA) = 0x68;
    }
    *(s16*)(arg0 + 0xE) = D_8007B5AC[i][1] + 0x10;
}
