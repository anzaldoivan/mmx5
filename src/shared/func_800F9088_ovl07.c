#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern Gm1C00 D_800D1C00;

void func_800F9088_ovl07(u8* obj, s32 b1, s32 b2) {
    u8 a1 = b1;
    u8 a2 = b2;
    u8 hi;
    s8 i;
    s8 v;
    u8* q;

    hi = g_Player[0x5C] & 0x80;
    if ((g_Player[0x5C] & 0x7F) < (s8)D_800D1C00.lim[(s8)g_Player[2]]) {
        func_800F94C8_ovl07(1);
        obj[0x85] = 4;
        obj[0x84] = a1;
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[0] |= 8;
    } else {
        obj[4] = 3;
    }
    if (!((g_Player[0x5C] & 0x7F) < (s8)D_800D1C00.lim[(s8)g_Player[2]])) {
        g_Player[0x5C] = D_800D1C00.lim[(s8)g_Player[2]] | hi;
    }
    for (i = 0; i < 2; i++) {
        q = &D_800D1C00.cnt[i];
        if (D_800D1C00.flags & (0x1000 << i)) {
            v = *q & 0x7F;
            if (v < 0x20) {
                v = a2 + v;
                if (v >= 0x20) {
                    v = 0x20;
                    play_sound(0, 0x18, 0);
                }
                *q = v | 0x80;
                return;
            }
        }
    }
}
