/* Shared body (DK-5), from the banked draft of func_800FC1C0_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

void DEDUP_NAME(EntFC1C0* obj) {
    s32 state;

    func_8002D9EC(obj, 0x30, 0x30);
    state = obj->state;
    if (state == 0) {
        obj->unk3 = 0;
        if (obj->timer == 0) {
            play_sound(2, 0x18, obj);
            obj->state++;
        }
        obj->timer--;
    } else if (state == 1) {
        ((s32(*)())animate_object)(obj);
        if (obj->unk45 == state) {
            obj->unk4 = 2;
        }
    }
}
