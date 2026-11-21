#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);

void func_800FB050_ovl01(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        func_8002A600(0x1E, 4, 2);
        *(s32*)(obj + 0x24) = 0x20000;
        *(s32*)(obj + 0x2C) = 0x2000;
        obj[6] = 2;
        *(u16*)(obj + 0xE) -= 4;
    }
}
