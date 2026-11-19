#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_80030CBC(u8*);
extern void snap_to_tile_slope(u8*, s32);
extern void player_clear_dash(u8*);

s32 func_800390A4(u8* p) {
    s32 r;
    s32 a;

    if (*(s8*)(p + 0xD3) != 0) {
        return 0;
    }
    if (p[0xF6] != 0) {
        if (--p[0xF6] != 0) {
            return 0;
        }
    }
    if (!(*(u16*)(p + 0x7C) & 4)) {
        return 0;
    }
    r = func_80030CBC(p);
    if (r == 0x2E) {
        if (*(s8*)(p + 0x8E) != 0 && *(s8*)(p + 2) == 0) {
            func_8003B33C(p, 0x90);
        } else {
            play_sound(0, 0x26, p);
            *(s8*)(p + 0x8E) = 0;
            func_8003B33C(p, 0xA0);
        }
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xC) = 0;
        p[0x5] = 0x1B;
        p[0x6] = 0;
        *(s32*)(p + 0x20) = 0;
        *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
        player_clear_dash(p);
        return 1;
    } else {
        if ((u8)(r - 0x25) >= 9) {
            return 0;
        }
        if (*(s32*)(p + 0x24) > 0) {
            return 0;
        }
        if (*(s8*)(p + 0x8E) != 0 && *(s8*)(p + 2) == 0) {
            switch (r) {
            case 0x2D:
                a = 0;
                break;
            case 0x25 ... 0x28:
                a = 1;
                if (p[0x15] == 0) {
                    a = 2;
                }
                break;
            default:
                a = 2;
                if (p[0x15] == 0) {
                    a = 1;
                }
                break;
            }
            func_8003B33C(p, a | 0x94);
        } else {
            play_sound(0, 0x26, p);
            switch (r) {
            case 0x2D:
                a = 0;
                break;
            case 0x25 ... 0x28:
                a = 1;
                if (p[0x15] == 0) {
                    a = 2;
                }
                break;
            default:
                a = 2;
                if (p[0x15] == 0) {
                    a = 1;
                }
                break;
            }
            func_8003B33C(p, a + 0xA3);
            *(s8*)(p + 0x8E) = 0;
        }
        p[0x5] = 0x1C;
        p[0x6] = 0;
        *(s32*)(p + 0x24) = 0;
        snap_to_tile_slope(p, r);
        player_clear_dash(p);
        return 1;
    }
}
