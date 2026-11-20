#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F9894_ovl29[];
extern u8 D_800F98A0_ovl29[];
extern s16 D_800FA648_ovl29;
extern s16 D_800FA64C_ovl29;

void func_800F389C_ovl29(u8* obj) {
    s16 x;
    s16 d;
    s32 v;

    if (*(s8*)(obj + 0x45) != 0) {
        *(u8**)(obj + 0x50) = D_800F98A0_ovl29;
    } else {
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
    }
    if (obj[0x70] & 8) {
        obj[6]++;
        set_animation(obj, 6);
        *(u8**)(obj + 0x50) = D_800F9894_ovl29;
        obj[0x60] = 4;
        obj[0x67] = 0;
        play_sound(2, 0xAF, obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        d = D_8009A0AA;
        x = *(s16*)(obj + 0xA);
        if (x < d) {
            if (x < D_800FA648_ovl29 - 0x50) {
                obj[0x15] = 0x40;
            } else {
                obj[0x15] = 0;
            }
        } else if (x < D_800FA64C_ovl29 + 0x50) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        v = 0xFFF80000;
        if (obj[0x15] != 0) {
            v = 0x80000;
        }
        *(s32*)(obj + 0x20) = v;
    }
    if (*(s8*)(obj + 0x45) == 1) {
        apply_object_motion(obj);
    }
    animate_object(obj);
}
