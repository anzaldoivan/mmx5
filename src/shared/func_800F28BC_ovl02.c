/* Shared body (DK-5), from the banked draft of func_800F28BC_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl02.h"
#include "mmx5/sound.h"
#include "addr.h"

#define SCR D_1F80004C.bytes

void DEDUP_NAME(ObjFE130* arg0) {
    if (arg0->unk45 == 2) {
        play_sound(2, 0x24, arg0);
        func_800F2AB4_ovl02(arg0, 0x10);
    } else if (arg0->unk45 == 3) {
        arg0->unk5 = 2;
        arg0->unk6 = 0;
    } else if (arg0->unk45 == 4) {
        SCR[0x82] = 0;
    }
}
