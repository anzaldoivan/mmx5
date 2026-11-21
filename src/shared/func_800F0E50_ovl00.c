#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

void func_800F0E50_ovl00(Obj0E50* obj) {
    obj->u16 = 7;
    switch (obj->state) {
    case 0:
    case 1:
        set_animation(obj, 4);
        obj->u15 = 0;
        obj->u5 = 0;
        break;
    case 2:
        set_animation(obj, 7);
        obj->u15 = 0;
        obj->u5 = 1;
        break;
    case 3:
        set_animation(obj, 7);
        obj->u15 = 0x40;
        obj->u5 = 2;
        break;
    }
    obj->u20 = 0;
    obj->u28 = 0;
    obj->u24 = 0;
    obj->u2C = 0;
    obj->u4 = 1;
}

extern u8 D_8009A197;
extern void (*D_800FA970_ovl00[])(Ent50*);

void func_800F0F0C_ovl00(Ent50* arg0) {
    s8 state = arg0->unk50->unk4;

    if (state != 1) {
        clear_object_slot(arg0);
        return;
    }
    if (D_8009A197 == 0) {
        arg0->unk18 = arg0->unk8;
        arg0->unk1C = arg0->unkC;
        D_800FA970_ovl00[arg0->unk5](arg0);
    }
    if (arg0->unk50->unk96 == 0) {
        arg0->unk3 = 0;
    } else {
        arg0->unk3 = state;
    }
}
