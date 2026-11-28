#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
void func_800F2038_ovl00(u8* arg0);

void func_800F237C_ovl00(u8* arg0) {
    u8* g = g_Player;
    u8* p;
    s32 a = *(s16*)(g + 0xA);
    s32 b = *(s16*)(arg0 + 0xA);
    s32 d = a - b;

    if (((d >= 0) ? (d < 0xA0) : (b - a < 0xA0)) ||
        (p = g_Player, *(s8*)(p + 0x98) != 0)) {
        if (--*(s16*)(arg0 + 0x7C) == -1) {
            func_800F2038_ovl00(arg0);
        }
    }
}
