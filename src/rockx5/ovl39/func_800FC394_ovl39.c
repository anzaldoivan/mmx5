#include "types.h"
#include "mmx5/globals.h"

void func_800FC394_ovl39(u8* a0) {
    u8* p = g_Player;

    if ((p[0x15] == 0 && *(s16*)(p + 0xA) < 0x1211) ||
        (p[0x15] == 0x40 && *(s16*)(p + 0xA) >= 0x1210)) {
        ((s32(*)())func_8003D29C)(0x14, g_Player[0x15]);
        a0[6]++;
    }
}
