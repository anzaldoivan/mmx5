#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F3A4C_ovl06(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u16 t;

    if (*(s8*)(obj + 0x45) == 7) {
        set_animation(obj, 0);
    }
    p = g_Player;
    if (((*(s16*)(obj + 0xE) - *(s16*)(p + 0xE)) < 0
             ? (*(s16*)(p + 0xE) - *(s16*)(obj + 0xE))
             : (*(s16*)(obj + 0xE) - *(s16*)(p + 0xE))) > 16) {
        q = g_Player;
        t = *(u16*)(obj + 0xE);
        if (*(s16*)(obj + 0xE) > *(s16*)(q + 0xE)) {
            *(s16*)(obj + 0xE) = t - 1;
        } else if (*(s16*)(obj + 0xE) < *(s16*)(q + 0xE)) {
            *(s16*)(obj + 0xE) = t + 1;
        }
        r = g_Player;
        if (((*(s16*)(obj + 0xE) - *(s16*)(r + 0xE)) < 0
                 ? (*(s16*)(r + 0xE) - *(s16*)(obj + 0xE))
                 : (*(s16*)(obj + 0xE) - *(s16*)(r + 0xE))) <= 16) {
            *(s32*)(obj + 0xC) = *(s32*)(obj + 0x1C);
        }
    }
    if (*(s16*)(obj + 0x7C) == 0) {
        if (*(s8*)(obj + 0x45) != 0) {
            set_animation(obj, 2);
            obj[6]++;
        }
    } else {
        *(s16*)(obj + 0x7C) = *(s16*)(obj + 0x7C) - 1;
    }
}
