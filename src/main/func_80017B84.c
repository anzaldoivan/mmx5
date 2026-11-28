#include "types.h"
#include "mmx5/globals.h"

extern void func_800177B0(s32, s32);
extern u8 D_800707CC[];

void func_80017B84(void) {
    u8* p = g_playthrough_state.u;
    u8* t;
    s32 i;
    s32 j;
    s32 a;

    if (*(u16*)(p + 0xC) != 0x10F) {
        t = D_800707CC;
        i = ((s8*)p)[0xC] * 8 + ((s8*)p)[0xD] * 4 + ((s8*)p)[0x44] * 2;
        a = t[i];
        j = i + 1;
        func_800177B0(a, t[j]);
    }
}
