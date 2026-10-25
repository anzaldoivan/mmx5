#include "types.h"

extern void func_8003AA4C(u8* arg0);
extern void func_8003B33C(u8*, s32);

void func_80037588(u8* arg0) {
    s8 state;

    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    state = arg0[0xCA];
    if (state > 0) {
        return;
    }
    if (state == 0) {
        arg0[0xA4] = 0;
        func_8003AA4C(arg0);
    } else if (state == -1) {
        func_8003B33C(arg0, 0x25);
        ((s8*)arg0)[0xCA] = -2;
    } else if (((s8*)arg0)[0x46] < 0) {
        func_8003B33C(arg0, 0x24);
        arg0[0xCA] = 1;
    }
}
