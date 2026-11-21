#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;
extern s16 D_800FA248_ovl03;

void func_800F45E4_ovl03(Obj4FE0* obj) {
    s16 x;
    s16 a;

    set_animation(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
        obj->unk15 = 0x40;
    } else {
        x = D_800FA242_ovl03 + 1;
        obj->unk15 = 0;
    }
    a = ratan2(D_800FA244_ovl03 - obj->unkE, x - obj->unkA);
    obj->unk20 = rcos(a) * 48;
    obj->unk24 = -rsin(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}
