#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern signed char D_800D1C0C;

void func_800F5864_ovl04(Obj5864* obj) {
    s32 goal = 0x70;

    if (D_800D1C0C != 12) {
        goal = 0x60;
    }
    if (obj->unk7C != 0) {
        if (--obj->unk7C == 0) {
            set_animation(obj, 3);
        }
        return;
    }
    if (goal < obj->unkE) {
        obj->unkE--;
    } else if (obj->unkE < goal) {
        obj->unkE++;
    } else {
        obj->unk7C = 30;
        obj->unk6++;
        set_animation(obj, 0x19);
    }
    animate_object(obj);
}

void func_800F5928_ovl04(Obj5928* obj) {
    if (--obj->timer == 0) {
        obj->timer = 60;
        obj->unk98 = 0;
        obj->state = 3;
        obj->sub = 0;
    }
    animate_object(obj);
}
