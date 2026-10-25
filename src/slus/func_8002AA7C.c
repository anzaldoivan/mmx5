#include "types.h"

extern u8 D_80071B0C[];
extern s8 D_800D1C00[];

void func_8002AA7C(u8* arg0) {
    u8* t = D_80071B0C;
    s8* p = D_800D1C00;
    s32 i = p[0xC] * 4 + p[0xD] * 2 + 1;
    arg0[4] = t[i];
}
