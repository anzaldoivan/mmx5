#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F09D8_ovl12(Obj09D8* obj) {
    if (obj->unk70 & 8) {
        if (obj->unk24 != 0) {
            play_sound(2, 0x42, obj);
        }
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
    }
    if (obj->unk46 == 0) {
        set_animation(obj, 7);
        play_sound(2, 0x3D, obj);
        obj->unk6++;
    }
}
