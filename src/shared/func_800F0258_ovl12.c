/* Shared body (DK-5), from the banked draft of func_800F0258_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void DEDUP_NAME(Obj05DC* obj) {
    s16 d;

    if (obj->unk45 == 1) {
        play_sound(2, 0x35, obj);
        d = D_8009A0AA - obj->unkA;
        if (d < 0) {
            obj->unk15 = 0;
            obj->unk20 = (d << 16) / 48;
        } else {
            obj->unk15 = 0x40;
            obj->unk20 = (d << 16) / 48;
        }
        obj->unk24 = 0x40000;
        obj->unk2C = 0x147A;
        obj->unk6++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
