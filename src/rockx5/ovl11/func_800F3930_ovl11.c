#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void silence_sound(s32, s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern u8 D_8009A1F8[];
extern s8 D_800D1C1D;
extern u8 D_800F9BE8_ovl11[];

void func_800F3930_ovl11(u8* a0) {
    u8* g;
    u8* h;
    u8* k;
    u8* m;
    u8* f;
    u8* e;
    s32 t;
    u16 c;
    s32 d;
    s32 x;
    s32 y;

    f = D_8009A1F8;
    if (*(s16*)(f + 0x28) == 0x750) {
        func_80028B18(0, 0x920, 0x840, D_800F9BE8_ovl11);
    }
    e = g_Player;
    x = *(s16*)(a0 + 0xA);
    y = *(s16*)(e + 0xA);
    d = x - y;
    if (d >= 0 ? d < 0x60 : (y - x) < 0x60) {
        g = g_Player;
        if (((s8*)g)[0xF3] == 0) {
            h = D_8009A1F8;
            t = a0[0x85] + 1;
            a0[0x85] = t;
            c = *(u16*)(h + 0x28);
            if ((s16)c > 0x5A0 && D_800D1C1D == 2) {
                if (!(t & 1)) {
                    *(s16*)(h + 0x28) = c - 1;
                }
            } else {
                k = D_8009A1F8;
                *(s16*)(k + 0x28) = 0x5A0;
            }
            move_object(a0, h, t, c);
        } else if ((u32)(g[0xFA] - 2) >= 2U) {
            h = D_8009A1F8;
            t = a0[0x85] + 1;
            a0[0x85] = t;
            c = *(u16*)(h + 0x28);
            if ((s16)c > 0x5A0 && D_800D1C1D == 2) {
                if (!(t & 1)) {
                    *(s16*)(h + 0x28) = c - 1;
                }
            } else {
                m = D_8009A1F8;
                *(s16*)(m + 0x28) = 0x5A0;
            }
            move_object(a0, h, t, c);
        }
    } else {
        silence_sound(5, 0x1C);
        a0[5] = 3;
    }
    if (*(s16*)(a0 + 0xA) >= 0xD28) {
        if (D_800D1C28[1] < 3) {
            silence_sound(5, 0x1C);
        }
        play_sound(5, 0x1B, a0);
        a0[5] = 8;
        func_8002A5C4(0x20, 2, 1);
    }
}
