#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800FA55C_ovl06(Obj0364* o) {
    func_800FAEF8_ovl06(o);
    set_animation(o, 7);
    o->p50 = D_800FF1CC_ovl06;
    o->p54 = D_800FF1D0_ovl06;
    o->timer = 1;
    o->h7E = 2;
    o->state++;
}

extern void func_800FAF38_ovl06(EntFA5C0*, s32, s32, s32);

void func_800FA5C0_ovl06(EntFA5C0* obj) {
    animate_object(obj);
    if (--obj->timer == 0) {
        func_800FAEF8_ovl06(obj);
        set_animation(obj, 7);
        obj->timer = 90;
        if (--obj->count == 0) {
            obj->state++;
        }
    }
    if (obj->mode == 2) {
        play_sound(2, 30, obj);
        func_800FAF38_ovl06(obj, obj->x, obj->y, 0);
    }
}

extern void func_800FAF38_ovl06(EntFA5C0*, s32, s32, s32);

void func_800FA674_ovl06(EntFA5C0* obj) {
    animate_object(obj);
    if (obj->mode == 2) {
        play_sound(2, 30, obj);
        func_800FAF38_ovl06(obj, obj->x, obj->y, 0);
    }
    if (--obj->timer == 0) {
        func_800F9180_ovl06(obj);
    }
}
