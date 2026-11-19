/* Shared body (DK-5), from the banked draft of func_800EEE5C_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(ObjEE5C* obj) {
    if (obj->unk24 < 0) {
        if (obj->unk20 < 0) {
            obj->unk20 = -0x10000;
        } else {
            obj->unk20 = 0x10000;
        }
    }
    if (obj->unk45 == 3) {
        obj->unk45 = 0;
        if (obj->unk15 == 0) {
            obj->unk15 = 0x40;
        } else {
            obj->unk15 = 0;
        }
    }
    if (obj->unk70 & 8) {
        if (obj->unk24 != 0) {
            play_sound(2, 0x42, obj);
        }
        obj->unk20 = 0;
        obj->unk24 = 0;
        obj->unk2C = 0;
    }
    if (obj->unk46 == 0) {
        if ((random_byte() & 3) == 0) {
            play_sound(2, 0x3D, obj);
            set_animation(obj, 8);
            if (D_8009A0AA > obj->unkA) {
                obj->unk15 = 0x40;
            } else {
                obj->unk15 = 0;
            }
            obj->unk7C = 0;
            obj->unk6++;
        } else {
            set_animation(obj, 1);
            obj->unk5 = D_800F1F94_ovl12[obj->unk86][obj->unk87++];
            obj->unk6 = 0;
        }
    }
    animate_object(obj);
    apply_object_motion(obj);
}
