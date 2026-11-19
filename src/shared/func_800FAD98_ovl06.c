/* Shared body (DK-5), from the banked draft of func_800FAD98_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);

void DEDUP_NAME(Ent08D8* obj) {
    apply_object_motion(obj);
    func_8002FB58(obj);
    animate_object(obj);
    if (obj->unk70 & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        obj->unk24 = 0x30000;
        obj->unk2C = 0x1000;
        obj->unk6 = obj->unk6 + 1;
    }
}
