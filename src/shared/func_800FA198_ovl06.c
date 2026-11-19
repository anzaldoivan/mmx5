/* Shared body (DK-5), from the banked draft of func_800FA198_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_800FF1EC_ovl06[];
extern u8 D_800FF1F0_ovl06[];

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 a;
    s32 t;
    s32 y;
    s32 x;

    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        set_animation(obj, 0xF);
        play_sound(2, 0x21, obj);
        *(u8**)(obj + 0x50) = D_800FF1EC_ovl06;
        *(u8**)(obj + 0x54) = D_800FF1F0_ovl06;
        p = g_Player;
        x = *(s16*)(p + 0xA);
        y = *(s16*)(p + 0xE);
        a = ratan2(*(s16*)(obj + 0xE) - y, x - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        t = rcos(a) * 16;
        *(s32*)(obj + 0x20) = t * 6;
        t = rsin(a) * 16;
        *(s32*)(obj + 0x24) = t * 6;
        obj[6]++;
    }
}
