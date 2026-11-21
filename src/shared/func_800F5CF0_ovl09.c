#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 D_800FB67C_ovl09;
extern s16 D_800FB680_ovl09;

void func_800F5CF0_ovl09(Obj5CF0* obj) {
    set_animation(obj, 5);
    obj->unk20 = 0;
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk7C = 0;
    if (D_800FB67C_ovl09 != 0) {
        D_800FB680_ovl09 = 0x78;
    } else {
        D_800FB680_ovl09 = 0xF0;
    }
    obj->state++;
    animate_object(obj);
    apply_object_motion(obj);
}
