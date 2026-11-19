/* Shared body (DK-5), from the banked draft of func_800F0138_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_800F52CC_ovl05[];

void DEDUP_NAME(Obj0138* arg0) {
    move_object(arg0);
    if (arg0->unk70 & 4) {
        arg0->unk2C = 0x1500;
        arg0->unk68 = D_800F52CC_ovl05;
        set_animation(arg0, 2);
        D_1F80004C.scr3594->unk84 = 0;
        arg0->unk6++;
    } else if (D_1F80004C.scr3594->unk82 - arg0->unkE >= 0xC0) {
        arg0->unk5 = 5;
        arg0->unk6 = 0;
    }
}
