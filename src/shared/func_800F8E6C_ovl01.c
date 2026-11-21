#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

void func_800F8E6C_ovl01(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        set_animation(obj, 0xE);
        if (obj[0x96] == 0) {
            if (obj[0x15] != 0) {
                if (obj[0x70] & 2) {
                    *(s32*)(obj + 0x20) = 0x1E000;
                } else {
                    *(s32*)(obj + 0x20) = 0x1B000;
                }
            } else if (obj[0x70] & 1) {
                *(s32*)(obj + 0x20) = -0x1E000;
            } else {
                *(s32*)(obj + 0x20) = -0x1B000;
            }
            *(s32*)(obj + 0x2C) = 0xE00;
            *(s32*)(obj + 0x24) = 0x2E800;
        } else if (*(s8*)(obj + 0x92) == 3) {
            if (obj[0x15] != 0) {
                *(s32*)(obj + 0x20) = -0x1B000;
            } else {
                *(s32*)(obj + 0x20) = 0x1B000;
            }
            *(s32*)(obj + 0x2C) = 0xE00;
            *(s32*)(obj + 0x24) = 0x2E800;
        }
        if (*(s8*)(obj + 0x92) == 2 || *(s8*)(obj + 0x92) == 4) {
            *(s32*)(obj + 0x20) /= 2;
        }
        if (*(s8*)(obj + 0x5C) < (s8)((s8)D_800D1CA2 / 3)) {
            *(s32*)(obj + 0x2C) = 0x145D;
            *(s32*)(obj + 0x24) = 0x38000;
            *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 120 / 100;
        }
        obj[6] = 1;
    }
    if (obj[0x96] != 0 && *(s8*)(obj + 0x92) != 3) {
        set_animation(obj, 0);
        obj[5] = 3;
        obj[6] = 0;
        *(s16*)(obj + 0x7C) = 60;
    } else {
        animate_object(obj);
    }
}

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);
extern signed char D_800D1C0C;
extern u8 D_800FD578_ovl01[];
extern u8 D_800FD57C_ovl01[];
extern u8 D_800FD608_ovl01[];

void func_800F905C_ovl01(u8* obj) {
    s32 lim;

    lim = 0x40;
    if (D_800D1C0C != 0xC) {
        lim = 0x120;
    }
    if (lim < *(s16*)(obj + 0xE)) {
        *(u8**)(obj + 0x68) = D_800FD608_ovl01;
    }
    if (*(s16*)(obj + 0x7C) >= 0x79) {
        if ((obj[0x70] & 8) && lim < *(s16*)(obj + 0xE)) {
            start_pad_vibration(5);
            play_sound(2, 7, obj);
            set_animation(obj, 0xF);
            *(u8**)(obj + 0x50) = D_800FD57C_ovl01;
            *(u8**)(obj + 0x54) = D_800FD578_ovl01;
            func_8002A600(0x1E, 4, 2);
            obj[6]++;
        }
        if (*(s16*)(obj + 0xA) > D_8009A0AA) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        apply_object_motion(obj);
        animate_object(obj);
    }
    (*(s16*)(obj + 0x7C))++;
}
