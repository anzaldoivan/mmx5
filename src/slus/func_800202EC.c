#include "types.h"

extern u8 D_8009A420[];
extern u8 D_800C9310;
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800202EC(u8* arg0) {
    u8 pad[16]; // !FAKE: unused local keeps the 0x10 stack frame
    u8* p = D_8009A420;

    if (((s8*)p)[4] == 0) {
        if (p[7] != 0) {
            D_800C9310 |= 1;
        }
        if (*(s16*)(arg0 + 0xA) == 0) {
            u8* g = D_800D1C00;
            arg0[0] = 9;
            g[1] = 0;
            g[2] = 0;
            g[3] = 0;
        } else {
            u8* q = D_8009A1F8;
            *(s16*)(q + 0xA) = 0;
            *(s16*)(q + 0xE) = 0;
            q[0x4C] = 1;
            q[3] = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        }
    }
}
