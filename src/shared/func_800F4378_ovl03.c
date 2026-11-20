/* Shared body (DK-5), from the banked draft of func_800F4378_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA246_ovl03;

void DEDUP_NAME(Obj3DD4* o) {
    if (D_8009A0AA > o->unkA) {
        o->unk15 = 0x40;
    } else {
        o->unk15 = 0;
    }
    if (o->unk20 < 0) {
        if (o->unkA <= D_800FA240_ovl03) {
            o->unkA = D_800FA240_ovl03;
            o->unk20 = 0;
        }
    } else if (o->unk20 > 0) {
        if (o->unkA >= D_800FA242_ovl03) {
            o->unkA = D_800FA242_ovl03;
            o->unk20 = 0;
        }
    }
    if (o->unkE >= D_800FA246_ovl03) {
        o->unkE = D_800FA246_ovl03;
        o->unk24 = 0;
    }
    if (o->unk20 == 0 && o->unk24 == 0) {
        set_animation(o, 5);
        if (((u8*)o)[0x8E] == 2) {
            o->unk15 = 0x40;
        } else {
            o->unk15 = 0;
        }
        o->unk7C = 0;
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}
