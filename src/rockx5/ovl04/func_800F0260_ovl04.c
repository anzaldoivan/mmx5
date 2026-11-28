#include "types.h"
#include "mmx5/globals.h"

extern s16 D_8009A202;

void func_800F0260_ovl04(void) {
    u8* p = g_Player;
    s16 d = *(s16*)(p + 0xA) - D_8009A202;
    u8 x;
    u8* q;

    if (d >= 0x138) {
        *(s16*)(p + 0xA) = D_8009A202 + 0x138;
    }
    if (d < -0x10) {
        q = g_playthrough_state.u;
        x = p[0x5C];
        *(s8*)(p + 0x5C) = -0x80;
        *(s32*)(q + 0xB8) += x & 0x7F;
    }
}
