/* Shared body (DK-5), from the banked draft of func_800FA09C_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void DEDUP_NAME(EntBD40* obj) {
    if (--obj->unk7C == 0) {
        play_sound(0, 0xE, 0);
        obj->unk7C = 2;
    }
    if (++obj->unk5C >= D_800D1CA2) {
        ((s32(*)())func_8003D2C4)();
        obj->unk6++;
    }
}
