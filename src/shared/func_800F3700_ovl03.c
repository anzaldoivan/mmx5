/* Shared body (DK-5), from the banked draft of func_800F3700_ovl03 by tools/wave/gate.py rescan. */
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

void DEDUP_NAME(Obj3700* obj) {
    s16 x;
    s16 a;
    s32 e;

    set_animation(obj, 1);
    if (obj->unkA < D_800FA248_ovl03) {
        x = D_800FA240_ovl03 - 1;
    } else {
        x = D_800FA242_ovl03 + 1;
    }
    e = obj->unkE + 1;
    a = ratan2(D_800FA244_ovl03 - e, x - obj->unkA);
    obj->unk20 = rcos(a) * 48;
    obj->unk24 = -rsin(a) * 48;
    obj->unk28 = 0;
    obj->unk2C = 0;
    obj->unk6++;
    animate_object(obj);
    apply_object_motion(obj);
}
