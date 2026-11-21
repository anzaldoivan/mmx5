#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void* D_800F4894_ovl02[];

void func_800F2FC4_ovl02(u8* a0) {
    u8* p = g_Player;
    s8 s;

    if (p[0xF7] == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        ((void (*)(u8*))D_800F4894_ovl02[((s8*)a0)[5]])(a0);
    }
    if (((s8*)p)[2] != 0 || p[0xFA] != 3) {
        func_800317B8(a0);
    }
    s = ((s8*)a0)[5];
    if (s != 0) {
        *(s32*)(a0 + 0x94) = s;
    }
    if (is_off_screen(a0, 0x20, 0x20) == 1) {
        a0[4]++;
    }
}

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F3098_ovl02
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
