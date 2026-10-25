#include "types.h"

extern u8 D_80071B0C[];
extern s8 D_800D1C00[];

void func_8002A8A0(u8* arg0) {
    u8* t = D_80071B0C;
    s8* p = D_800D1C00;
    arg0[4] = t[p[0xD] * 2 + p[0xC] * 4];
}
