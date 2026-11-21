#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"

extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];

void func_800F9AD8_ovl06(Obj9AD8* obj) {
    set_animation(obj, 2);
    obj->unk50 = D_800FF1CC_ovl06;
    obj->unk54 = D_800FF1D0_ovl06;
    obj->timer = 120;
    obj->state++;
}

void func_800F9B2C_ovl06(u8* obj) {
    animate_object(obj);
    if ((*(u16*)(obj + 0x7C) & 0x1F) == 0) {
        func_800FAEF8_ovl06(obj);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800F9180_ovl06(obj);
    }
}
