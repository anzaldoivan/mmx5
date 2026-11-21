#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F05DC_ovl12(Obj05DC* obj) {
    s16 d;

    if (obj->unk45 == 1) {
        play_sound(2, 0x35, obj);
        d = D_8009A0AA - obj->unkA;
        if (d < 0) {
            obj->unk15 = 0;
            obj->unk20 = (d << 16) / 40;
        } else {
            obj->unk15 = 0x40;
            obj->unk20 = (d << 16) / 40;
        }
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1999;
        obj->unk6++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}
