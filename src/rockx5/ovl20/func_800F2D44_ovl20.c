#include "types.h"
#include "mmx5/globals.h"

extern void func_80032CEC();

void func_800F2D44_ovl20(u8* arg0) {
    s8* d;
    s8* e;
    s32 t;
    s32 k;
    u32 v;

    arg0[0] = 0x51;
    d = g_playthrough_state.s;
    t = d[0x26];
    if (t == 1 && d[0x28] == ((s8*)arg0)[2]) {
        arg0[0] = t;
        *(s16*)(arg0 + 0x34) = 0x7FFF;
        arg0[3] = t;
        return;
    }
    e = g_playthrough_state.s;
    t = e[0x27];
    if (t == 0x20) {
        if (e[0x28] != ((s8*)arg0)[2]) {
            *(s16*)(arg0 + 0x34) = 0x294A;
            func_80032CEC();
            return;
        }
    } else if (e[0x2B] == 0 && e[0x28] != ((s8*)arg0)[2]) {
        k = 0xA00;
        v = (u32)(t * k) / 31 >> 8;
        if (v >= 0x20) {
            v = 0x1F;
        }
        v = v | (v << 5) | (v << 10);
        *(s16*)(arg0 + 0x34) = v;
        func_80032CEC();
        return;
    }
    arg0[3] = 0;
}
