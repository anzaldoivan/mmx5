#include "types.h"

extern u16 D_8007B5AC[][2];
extern u8 D_800D1C03;

void func_8004F004(u8* arg0) {
    s32 i;

    i = ((s8*)arg0)[2] >> 4;
    arg0[0x47] = D_800D1C03;
    *(u16*)(arg0 + 0xA) = D_8007B5AC[i][0];
    *(u16*)(arg0 + 0xE) = D_8007B5AC[i][1];
}
