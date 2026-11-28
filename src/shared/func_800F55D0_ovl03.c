#include "types.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void func_800F55D0_ovl03(u8* obj) {
    s32 v;

    v = *(s32*)(obj + 0x20);
    if (v < 0) {
        if (*(s16*)(obj + 0xA) <= D_800FA240_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (v > 0) {
        if (*(s16*)(obj + 0xA) >= D_800FA242_ovl03) {
            *(s16*)(obj + 0xA) = D_800FA242_ovl03;
        clear:
            *(s32*)(obj + 0x20) = 0;
        }
    }
    if (*(s16*)(obj + 0xE) <= D_800FA244_ovl03) {
        *(s16*)(obj + 0xE) = D_800FA244_ovl03;
        *(s32*)(obj + 0x24) = 0;
    }
    if (*(s32*)(obj + 0x20) == 0 && *(s32*)(obj + 0x24) == 0) {
        D_800D50DC = 0;
        D_8009A42C = 0;
        D_80093E66 = 0;
        func_8002C218();
        set_animation(obj, 0xA);
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F56D8_ovl03(u8* obj) {
    s16 t;

    t = *(s16*)(obj + 0x7C) % 60;
    if (t == 0) {
        play_sound(2, 0x10, obj);
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_800C9310.b |= 1;
        D_80093E68 = 0x7C00;
    } else if (t == 1) {
        D_800D50DE = 0;
        D_8009A42E = 0;
        D_80093E68 = 0;
        D_800C9310.b |= 1;
    }
    if (++*(s16*)(obj + 0x7C) == 0xB6) {
        play_sound(2, 0xD, obj);
        *(s32*)(obj + 0x54) = 0;
        D_800D1C10.u = 2;
        *(s16*)(obj + 0x7C) = 0;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
