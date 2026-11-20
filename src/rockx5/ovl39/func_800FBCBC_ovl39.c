#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern s32 func_8002A600(s32, s32, s32);
extern void func_800FBAF8_ovl39(u8* obj);

void func_800FBCBC_ovl39(u8* obj) {
    u16 t;

    animate_object(obj);
    func_800317B8(obj);
    t = *(u16*)(obj + 0x8C);
    if (t != 0) {
        *(u16*)(obj + 0x8C) = t - 1;
        return;
    }
    if (*(s32*)(obj + 0x24) > 0x7FFFF) {
        *(s32*)(obj + 0x24) = 0x80000;
    } else if (*(s32*)(obj + 0x24) <= -0x80000) {
        *(s32*)(obj + 0x24) = -0x80000;
    }
    if (*(s32*)(obj + 0x20) > 0x7FFFF) {
        *(s32*)(obj + 0x20) = 0x80000;
    } else if (*(s32*)(obj + 0x20) <= -0x80000) {
        *(s32*)(obj + 0x20) = -0x80000;
    }
    apply_object_motion(obj);
    if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= 0x1268) {
            play_sound(2, 0xAA, obj);
            start_pad_vibration(5);
            func_8002A5C4(0x20, 4, 1);
            *(s16*)(obj + 0xA) = 0x1268;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) < 0x11B9) {
            play_sound(2, 0xAA, obj);
            start_pad_vibration(5);
            func_8002A5C4(0x20, 4, 1);
            *(s16*)(obj + 0xA) = 0x11B8;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s32*)(obj + 0x24) < 0) {
        if (*(s16*)(obj + 0xE) >= 0x808) {
            play_sound(2, 0xAA, obj);
            start_pad_vibration(5);
            func_8002A600(0x20, 4, 1);
            *(s16*)(obj + 0xE) = 0x808;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s16*)(obj + 0xE) < 0x7B9) {
        play_sound(2, 0xAA, obj);
        start_pad_vibration(5);
        func_8002A600(0x20, 4, 1);
        *(s16*)(obj + 0xE) = 0x7B8;
        func_800FBAF8_ovl39(obj);
    }
    if (obj[0x8E] == 4) {
        set_animation(obj, 0x19);
        obj[5]++;
    }
}
