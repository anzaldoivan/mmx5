#include "types.h"
#include "mmx5/globals.h"

void func_800F13C0_ovl20(u8* a0) {
    s32 i;
    s32 sum;

    i = 0;
    sum = 0;
    g_playthrough_state.s[0x2C] = 0;
    while (1) {
        if (g_playthrough_state.s[0xCB] & 1) {
            sum += g_playthrough_state.s[0xC6 + i];
        } else {
            sum += g_playthrough_state.s[0xC2 + i];
        }
        i++;
        if (i >= 4) {
            break;
        }
    }
    sum *= 4;
    sum += g_playthrough_state.s[0xCA];
    g_playthrough_state.s[0x32] = sum;
    a0[2]++;
}

void func_800F143C_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u16 v;

    b = D_8009A1F8.u;
    if (*(s16*)(b + 0x5E) < 0x141) {
        *(s16*)(b + 0x5E) -= 8;
    } else {
        *(s16*)(b + 0x5E) += 8;
    }
    c = D_8009A1F8.u;
    v = *(u16*)(c + 0x5E);
    if (v == 0 || v >= 0x3C0) {
        *(s16*)(c + 0x5E) = 0x3C0;
        c[0xA0] = 1;
        arg0[2]++;
    }
}
