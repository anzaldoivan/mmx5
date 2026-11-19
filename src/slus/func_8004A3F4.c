#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800771B8[])(s8*);

void func_8004A3F4(s8* e) {
    s32 f = (s8)g_Player[0xD3] != 0;

    if ((s8)g_Player[0xD4] != 0) {
        f = 1;
    }
    if ((s8)g_Player[0x93] != 7) {
        f = 1;
    }
    if (f) {
        e[4] = 3;
    }
    D_800771B8[e[4]](e);
}
