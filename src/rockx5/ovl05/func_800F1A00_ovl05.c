#include "types.h"
#include "mmx5/graphics.h"

void func_800F1A00_ovl05(Obj1A00* obj) {
    u8 t = obj->unk45;

    if (obj->unk45 == 2) {
        s8 s = obj->unk2;
        if (s >= 0) {
            if (s < 3) {
                set_animation(obj, 0xE);
                obj->unk88 = 0xE;
            } else if (s < 6) {
                set_animation(obj, 1);
                obj->unk88 = 0xB4;
            }
        }
        obj->unk6++;
        return;
    }
    obj->unk8D = -t;
    obj->unk8F = t;
}
