#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C0F;

void func_800F39BC_ovl05(u8* arg0) {
    u8* p = g_Player;

    if ((p[0x5C] & 0x7F) && *(s16*)(p + 0xA) >= 0x1134) {
        D_800D1C0F = 0x40;
        func_8002D720(arg0);
    }
}
