#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F8AA8_ovl27(u8* obj) {
    u8* p;
    u8* q;
    s32 t;
    s32 d;
    s32 v;
    s32 one;

    t = *(u16*)(obj + 0x7C) - 1;
    *(u16*)(obj + 0x7C) = t;
    if ((t << 16) == 0) {
        set_animation(obj, 0x13);
        p = g_Player;
        *(s32*)(obj + 0x20) = 0;
        d = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
        if (d >= 0) {
            if (d < 8) {
                one = 1;
                v = 3;
                goto set; // !FAKE: goto kept for the matching branch layout
            }
            goto far; // !FAKE: goto kept for the matching branch layout
        }
        if (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE) >= 8) {
        far: // !FAKE: label kept for the matching branch layout
            q = g_Player;
            if (*(s16*)(q + 0xE) < *(s16*)(obj + 0xE)) {
                play_sound(2, 0x66, obj);
                *(s32*)(obj + 0x24) = 0x20000;
                v = obj[6] + 1;
                obj[6] = v;
                return;
            }
            play_sound(2, 0x66, obj);
            *(s32*)(obj + 0x24) = 0xFFFE0000;
            v = obj[6] + 1;
            obj[6] = v;
            return;
        }
        one = 1;
        v = 3;
    set: // !FAKE: label kept for the matching branch layout
        *(u16*)(obj + 0x7C) = one;
        obj[6] = v;
    }
}
