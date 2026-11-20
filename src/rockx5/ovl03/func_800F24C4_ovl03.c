#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);

void func_800F24C4_ovl03(u8* obj) {
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        obj[6] = 2;
        play_sound(5, 0x26, 0);
        if (((s8*)obj)[2] != 1) {
            func_8005019C(0x21, 2, obj, 0x18, 3);
            func_8005019C(0x22, 2, obj, 0x18, 3);
        }
    }
}
