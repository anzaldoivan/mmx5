#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern u16 D_800FDA98_ovl01[];

void func_800F93EC_ovl01(u8* obj) {
    s32 off;
    u8* g;
    u8* h;

    off = 0x1F0;
    if (g_playthrough_state.s[0xC] != 0xC) {
        off = 0x24F0;
    }
    if (*(s16*)(obj + 0x7E) >= 0x20) {
        g = g_Player;
        *(s16*)(obj + 0xA) =
            D_800FDA98_ovl01[D_800FDA5C_ovl01.h[(*(s16*)(g + 0xA) - off) / 16]];
        if (*(s16*)(g + 0xA) < *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        h = g_Player;
        switch (D_800FDA5C_ovl01.h[(*(s16*)(h + 0xA) - off) / 16]) {
        case 1:
        case 3:
        case 5:
            obj[0x15] = 0x40;
            set_animation(obj, 7);
            if (g_playthrough_state.s[0xC] != 0xC) {
                if (random_byte() & 1) {
                    *(s16*)(obj + 0xE) = 0x158;
                } else {
                    *(s16*)(obj + 0xE) = 0x170;
                }
            } else {
                if (random_byte() & 1) {
                    *(s16*)(obj + 0xE) = 0x78;
                } else {
                    *(s16*)(obj + 0xE) = 0x90;
                }
            }
            obj[6] = 4;
            play_sound(2, 0xC, obj);
            func_800FB418_ovl01(0, 0, obj, 0xA);
            func_800FB418_ovl01(0x1E, D_800FD9CC_ovl01, obj, 4);
            break;
        case 2:
        case 4:
            set_animation(obj, 8);
            *(s32*)(obj + 0x50) = 0;
            *(s32*)(obj + 0x54) = 0;
            if (g_playthrough_state.s[0xC] != 0xC) {
                *(s16*)(obj + 0xE) = 0x1B0;
            } else {
                *(s16*)(obj + 0xE) = 0xD0;
            }
            obj[6] = 3;
            func_80050650(0x33, *(s16*)(obj + 0xA) - 0x28,
                          *(s16*)(obj + 0xE) - 0x10, *(s16*)(obj + 0xA) + 0x28,
                          *(s16*)(obj + 0xE), 0x10);
            play_sound(2, 0xC, obj);
            func_800FB418_ovl01(0x14, D_800FD9CC_ovl01, obj, 3);
            obj[0x94] = 0;
            break;
        }
        func_8002A5C4(0x14, 4, 2);
    }
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) += 1;
}
