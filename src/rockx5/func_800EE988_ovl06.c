#include "types.h"

extern u8 D_800D1DC0[][0xB0];
extern void func_8002D720(u8* arg0);

void func_800EE988_ovl06(u8* arg0) {
    u8* p;
    s32 idx;

    arg0[4] = 1;
    arg0[5] = 0;
    idx = ((s8*)arg0)[2];
    p = D_800D1DC0[idx];
    p[0] = 0x41;
    p[1] = 1;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[2] = arg0[2];
    *(s32*)&D_800D1DC0[idx][0x10] = *(s32*)(arg0 + 0x10);
    *(s32*)&D_800D1DC0[idx][0x8] = *(s32*)(arg0 + 0x8);
    *(s32*)&D_800D1DC0[idx][0xC] = *(s32*)(arg0 + 0xC);
    func_8002D720(arg0);
}
