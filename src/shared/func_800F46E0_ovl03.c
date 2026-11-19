/* Shared body (DK-5), from the banked draft of func_800F46E0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FA240_ovl03;
extern s16 D_800FA242_ovl03;
extern s16 D_800FA244_ovl03;

void DEDUP_NAME(Obj3DD4* obj) {
    s16 d;

    if (obj->unk20 < 0) {
        if (obj->unkA <= D_800FA240_ovl03) {
            obj->unkA = D_800FA240_ovl03;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (obj->unk20 > 0) {
        if (obj->unkA >= D_800FA242_ovl03) {
            obj->unkA = D_800FA242_ovl03;
        clear:
            obj->unk20 = 0;
        }
    }
    if (obj->unkE <= D_800FA244_ovl03) {
        obj->unkE = D_800FA244_ovl03;
        obj->unk24 = 0;
    }
    if (obj->unk20 == 0 && obj->unk24 == 0) {
        set_animation(obj, 3);
        ((u8*)obj)[0x62] = 3;
        if (obj->unk15 == 0) {
            d = D_8009A0AA - D_800FA242_ovl03;
            if (d < 0x10 - (D_800FA242_ovl03 - D_800FA240_ovl03)) {
                d = 0x10 - (D_800FA242_ovl03 - D_800FA240_ovl03);
            }
            if (d >= -0xF) {
                d = -0x10;
            }
        } else {
            d = D_8009A0AA - D_800FA240_ovl03;
            if (D_800FA242_ovl03 - D_800FA240_ovl03 - 0x10 < d) {
                d = D_800FA242_ovl03 - D_800FA240_ovl03 - 0x10;
            }
            if (d < 0x10) {
                d = 0x10;
            }
        }
        obj->unk24 = 0xFFFA0000;
        *(s32*)((u8*)obj + 0x2C) = -0x2800;
        obj->unk7E = 0;
        obj->unk6++;
        obj->unk20 = (d << 16) / 40;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
