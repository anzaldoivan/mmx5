#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern u8 D_800FD2BC_ovl01[];

void func_800F78C0_ovl01(u8* obj) {
    s8 state = *(s8*)(obj + 7);

    if (state == 0) {
        play_sound(2, 6, obj);
        *(s16*)(obj + 0x8C) = 0x30;
        obj[7]++;
    } else if (state == 1) {
        if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 5) {
            obj[4] = 3;
        } else if (--*(s16*)(obj + 0x8C) == -1) {
            set_animation(obj, 0xA);
            play_sound(2, 5, obj);
            *(u8**)(obj + 0x50) = D_800FD2BC_ovl01;
            *(s32*)(obj + 0x20) = 0x30000;
            *(s16*)(obj + 0xA) -= 0x40;
            obj[7]++;
        }
    } else if (state == 2) {
        move_object(obj);
    }
}
