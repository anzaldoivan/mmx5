#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

void func_800F1DB4_ovl11(u8* obj) {
    obj[0x15] = (*(u8**)(obj + 0x50))[0x15];
    ((s32(*)())set_animation)(obj, 0xD);
    obj[3] = 1;
    obj[4] = 1;
    *(u16*)(obj + 0x42) &= 0x7FFF;
}

extern u8 D_8009A197;

void func_800F1E04_ovl11(Ent1E04* obj) {
    Ent1E04* p;

    if (D_8009A197 == 0) {
        animate_object(obj);
    }
    p = obj->parent;
    if (p->active == 0 || p->link != 0) {
        obj->state = 2;
    }
    obj->x = p->x;
    obj->y = p->y;
    func_8002D9EC(obj, 0x30, 0x30);
}
