/* Shared body (DK-5), from the banked draft of func_800EFBF8_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(EntFBF8* obj) {
    s32 v;

    animate_object(obj);
    move_object(obj);
    if (--obj->unk7C == 0) {
        v = -0x20000;
        if (obj->unk15 & 0x40) {
            v = 0x20000;
        }
        obj->unk20 = v;
        obj->unk5 = 5;
        obj->unk6 = 0;
    }
}
