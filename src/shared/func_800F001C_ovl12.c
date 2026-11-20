/* Shared body (DK-5), from the banked draft of func_800F001C_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern u8 D_800F1F94_ovl12[][6];

void DEDUP_NAME(Obj001C* obj) {
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
}
