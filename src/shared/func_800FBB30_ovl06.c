#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

void func_800FBB30_ovl06(Obj0658* arg0) {
    arg0->unk28 = 0;
    if (arg0->unk15 == 0) {
        arg0->unk20 = 0xFFFE0000;
    } else {
        arg0->unk20 = 0x20000;
    }
    arg0->unk24 = 0x20000;
    arg0->unk2C = 0x1000;
    arg0->unk6++;
}

extern u8 D_800FF69C_ovl06[];
extern u8 D_800FF6A0_ovl06[];
extern u8 D_800FF6A4_ovl06[];

void func_800FBB70_ovl06(ObjBB70* obj) {
    ((s32(*)())apply_object_motion)(obj);
    if (obj->unk70 == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj->unk70 == 0) {
            return;
        }
    }
    if (obj->unk70 & 4) {
        if (obj->unk70 & 1) {
            obj->unk15 = 0;
        } else if (obj->unk70 & 2) {
            obj->unk15 = 0x40;
        }
    }
    set_animation(obj, 1);
    obj->unk68 = D_800FF6A4_ovl06;
    obj->unk50 = D_800FF69C_ovl06;
    obj->unk54 = D_800FF6A0_ovl06;
    obj->state++;
}

void func_800FBC28_ovl06(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) != 0) {
        arg0[4] = 2;
    }
}
