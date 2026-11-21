#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

void func_800F0AD0_ovl12(Obj5CF0* obj) {
    play_sound(2, 0x3E, obj);
    set_animation(obj, 10);
    obj->unk20 = 0;
    obj->unk24 = 0x20000;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk7C = 0;
    obj->state++;
}
