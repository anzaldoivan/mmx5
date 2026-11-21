#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"

extern u8 D_80101808_ovl07[];
extern u8 D_80101804_ovl07[];

void func_800FC928_ovl07(ObjFC928* obj) {
    obj->p54 = D_80101808_ovl07;
    obj->p50 = D_80101804_ovl07;
    D_1F80004C.bytes[0x92] = 0;
    set_animation(obj, 0x16);
    obj->timer = 40;
    obj->state++;
}

void func_800FC988_ovl07(u8* obj) {
    animate_object(obj);
    if (--*(s16*)(obj + 0x7C) == -1) {
        D_1F80004C.bytes[0x88] = 0x3C;
        func_800FB030_ovl07(obj);
    }
}
