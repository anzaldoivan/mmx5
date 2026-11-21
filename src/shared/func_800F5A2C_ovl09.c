#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F5A2C_ovl09(u8* obj) {
    set_animation(obj, 3);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x7C) = 0x28;
    obj[6]++;
    animate_object(obj);
    apply_object_motion(obj);
}

extern s8 func_8002E024(Obj5A88*, u8*);

void func_800F5A88_ovl09(Obj5A88* obj) {
    s8 v;

    if (--obj->timer == 0) {
        set_animation(obj, 4);
        v = func_8002E024(obj, g_Player);
        obj->unk92 = v;
        if ((u8)v < 9) {
            obj->unk92 = 0x1F;
        } else if ((u8)(v - 9) < 8) {
            obj->unk92 = 0x11;
        }
        obj->unk84 = 0;
        obj->unk88 = 0x2000;
        obj->timer = 0;
        obj->state++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern s16 D_800FB61E_ovl09;
extern u8 D_800FAD58_ovl09[][6];

void func_800F5B3C_ovl09(Ent5B3C* e) {
    if (e->unkE <= D_800FB61E_ovl09) {
        e->unkE = D_800FB61E_ovl09;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97++];
        e->unk6 = 0;
    }
    animate_object(e);
    apply_object_motion(e);
}
