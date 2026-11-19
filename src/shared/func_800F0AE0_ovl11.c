/* Shared body (DK-5), from the banked draft of func_800F0AE0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void func_800F1148_ovl11(u8* obj);
extern void func_800F0F78_ovl11(u8* obj);
extern s8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (D_800D1C00[0x44] != (*(s32*)(obj + 0x84) & 1)) {
        set_animation(obj, 2);
    } else {
        set_animation(obj, 1);
    }
    if (*(s8*)(obj + 2) == 0) {
        if (*(s32*)(obj + 0x84) == 2 && D_800D1C00[0x44] == 0) {
            play_sound(2, 0x2F, obj);
            func_800F1148_ovl11(obj);
        } else {
            play_sound(2, 0x2F, obj);
            func_800F0F78_ovl11(obj);
        }
    } else {
        play_sound(2, 0x2F, obj);
        func_800F0F78_ovl11(obj);
    }
    *(s16*)(obj + 0x7C) = 0x4B;
    if (*(s8*)(obj + 2) == 2) {
        *(s16*)(obj + 0x7C) = 0x32;
    }
    obj[6]++;
}
