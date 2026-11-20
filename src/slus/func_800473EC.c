#include "types.h"
#include "mmx5/globals.h"

extern void (*D_80076FD8[])(u8*);

void func_800473EC(u8* a0) {
    s8* g = (s8*)g_Player;
    s32 flag;

    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    flag = g[0xD3] != 0;
    if (g[0xD4] != 0) {
        flag = 1;
    }
    if (g[0x93] != 3) {
        flag = 1;
    }
    if (g[0x96] == 12) {
        flag = 1;
    }
    if (flag) {
        a0[4] = 3;
    }
    a0[0x8C] = a0[0x70] | a0[0x71];
    D_80076FD8[((s8*)a0)[4]](a0);
    func_8002FB58(a0);
    a0[0x71] = 0;
}
