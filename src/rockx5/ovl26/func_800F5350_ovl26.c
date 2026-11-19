#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);

void func_800F5350_ovl26(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        play_sound(2, 0x63, obj);
        func_8002A600(0x1E, 4, 1);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x30000;
        } else {
            *(s32*)(obj + 0x20) = -0x30000;
        }
        obj[6]++;
        set_animation(obj, 0x13);
    }
}
