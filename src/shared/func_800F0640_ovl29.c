#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F0640_ovl29(Ent0640* obj) {
    u8 mode;

    animate_object(obj);
    if (obj->unk45 == 2) {
        obj->unk80 = 1;
        obj->unk24 = 0x60000;
        mode = obj->unk8C;
        obj->unk2C = 0x4000;
        if (mode == 0) {
            if (obj->unk15 == 0) {
                obj->unk20 = -0x1CCCC;
            } else {
                obj->unk20 = 0x1CCCC;
            }
        } else if (mode == 1) {
            obj->unk20 = 0;
        } else if (mode == 2) {
            if (obj->unk15 == 0) {
                obj->unk20 = 0x1CCCC;
            } else {
                obj->unk20 = -0x1CCCC;
            }
        }
        apply_object_motion(obj);
        obj->unk06 = 1;
    }
}

void func_800F06F8_ovl29(Ent06F8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    if (obj->unk24 == 0 && obj->unk8C != 0) {
        obj->unk2C = 0;
        obj->state = 2;
        obj->substate = 0;
    }
    if (obj->flags70 & 8) {
        obj->unk24 = 0;
        obj->unk2C = 0;
        set_animation(obj, 0x11);
        obj->substate = 2;
    }
}

void func_800F077C_ovl29(u8* arg0) {
    animate_object();
    if (*(s8*)(arg0 + 0x45) != 0) {
        arg0[0x80] = 0;
        arg0[5] = 3;
        arg0[6] = 0;
    }
}
