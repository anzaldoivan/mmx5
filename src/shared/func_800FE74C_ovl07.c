/* Shared body (DK-5), from the banked draft of func_800FE74C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 func_800FD530_ovl07(EntFE4F8*, s32);

void DEDUP_NAME(EntFE4F8* o) {
    animate_object(o);
    move_object(o);
    if (func_800FD530_ovl07(o, 1) != 0) {
        o->unk3 = 0;
        o->unkA = o->unk92;
        if (o->unk8D == 0) {
            set_animation(o, 0xE);
        } else {
            set_animation(o, 0x18);
        }
        o->unk8E = 1;
        o->unk6 = 3;
        return;
    }
    ((s32(*)())func_8002FB58)(o);
    if (!(o->unk70 & 1)) {
        return;
    }
    if (o->unk8D == 0) {
        set_animation(o, 9);
    } else {
        set_animation(o, 0x18);
    }
    o->unk67 = 0;
    o->unk20 = 0;
    o->unk24 = 0;
    o->unk6++;
}
