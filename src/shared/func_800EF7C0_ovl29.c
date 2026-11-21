#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"

void func_800EF7C0_ovl29(ObjEF7C0* obj) {
    if (obj->unk7C == 0) {
        set_animation(obj, 5);
        obj->unk20 = (obj->unk15 & 0x40) ? 0x40000 : -0x40000;
        obj->unk6 = 1;
    } else {
        obj->unk7C--;
    }
    animate_object(obj);
}

extern s32 D_8009A0A8;

void func_800EF82C_ovl29(ObjEF82C* self) {
    self->unk84 += 4;
    if (self->unk84 < 0 ||
        (self->unk15 == 0 ? D_8009A0A8 > self->x : D_8009A0A8 < self->x)) {
        self->unk28 = -0x1800;
        self->unk6 = 2;
    }
    if (((self->unk70 & 2) && self->unk15 == 0) ||
        ((self->unk70 & 1) && self->unk15 != 0)) {
        self->unk60 = 3;
        self->unk28 = 0;
        self->unk20 = 0;
        self->unk5 = 7;
        self->unk6 = 0;
    }
    move_object(self);
    animate_object(self);
}

void func_800EF920_ovl29(EntF920* obj) {
    s32 v = obj->velX;
    if ((v >= 0 ? v : -v) <= 0xFFFF || ((obj->flags & 2) && obj->unk15 == 0) ||
        ((obj->flags & 1) && obj->unk15 != 0)) {
        obj->unk60 = 3;
        obj->velX = 0;
        obj->unk28 = 0;
        obj->state = 7;
        obj->substate = 0;
    }
    apply_object_motion(obj);
    animate_object(obj);
}

extern u8 D_800750C0[];

void func_800EF9C8_ovl29(ObjEF9C8* obj) {
    animate_object(obj);
    if (obj->unk70 & 8) {
        if (obj->unk80 != 0) {
            obj->unk58 = D_800750C0;
            obj->unk60 = 3;
            obj->unk5 = 7;
        } else {
            set_animation(obj, 1);
            obj->unk5 = 2;
        }
        obj->unk6 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->unk67 = 0;
        return;
    }
    apply_object_motion(obj);
}
