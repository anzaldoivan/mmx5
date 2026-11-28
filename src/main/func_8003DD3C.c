#include "types.h"
#include "mmx5/sound.h"

extern void player_reset_charge(u8* p);
extern s8 D_800D1C1C;
extern s8 D_80074A1C[];
extern s8 D_80074A28[];
extern s8 D_80074A34[];

void func_8003DD3C(u8* p) {
    s32 a;
    s32 m;
    s8 i;

    if (*(s8*)(p + 0xD3) != 0) {
        return;
    }
    if (*(s8*)(p + 0xF0) != 0) {
        return;
    }
    if (*(s8*)(p + 0x99) != 0) {
        return;
    }
    if (*(s8*)(p + 0xD5) != 0) {
        return;
    }
    if (*(s8*)(p + 0xF3) != 0) {
        return;
    }
    if (D_800D1C1C != 0) {
        return;
    }
    if (p[0xF7] != 0) {
        return;
    }

    a = *(u16*)(p + 0x7C) & 0x600;
    m = *(u16*)(p + 0x80) & 0x600;
    if (a == 0x600 || m == 0x600) {
        if (*(s8*)(p + 0x93) != 0) {
            p[0x93] = 0;
            player_reset_charge(p);
            play_sound(0, 0xC, 0);
        }
    } else if (m != 0) {
        i = D_80074A34[*(s8*)(p + 0x93)];
        if (m & 0x200) {
            do {
                i++;
                if (i == 9) {
                    i = 0;
                    break;
                }
            } while (!(D_80074A1C[i] & p[0xC9]));
        } else {
            for (;;) {
                i--;
                if (i < 0) {
                    i = 8;
                }
                if (i == 0) {
                    break;
                }
                if (D_80074A1C[i] & p[0xC9]) {
                    break;
                }
            }
        }
        i = D_80074A28[i];
        if ((s8)p[0x93] != i) {
            p[0x93] = i;
            player_reset_charge(p);
            play_sound(0, 0xC, 0);
        }
    }
}
