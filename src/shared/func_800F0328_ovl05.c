#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F0328_ovl05(Obj0328* e) {
    if (((D_8009A0AA - e->unkA) >= 0 ? (D_8009A0AA - e->unkA)
                                     : (e->unkA - D_8009A0AA)) > 0x90) {
        e->unk5 = 5;
        e->unk6 = 0;
        return;
    }
    e->unk24 = 0;
    e->unk2C = 0x2000;
    e->unk6++;
}

extern u8 D_800F52C8_ovl05[];

void func_800F038C_ovl05(Obj038C* obj) {
    apply_object_motion(obj);
    if (obj->flags70 & 8) {
        obj->unk54 = D_800F52C8_ovl05;
        set_animation(obj, 14);
        D_1F80004C.bytes[0x84] = 1;
        obj->unk24 = 0;
        obj->unk2C = 0;
        obj->unk20 = 0;
        obj->unk28 = 0;
        obj->state++;
    }
}
