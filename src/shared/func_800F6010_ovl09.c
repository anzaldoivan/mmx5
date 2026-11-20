/* Shared body (DK-5), from the banked draft of func_800F6010_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void silence_sound(s32, s32);

void DEDUP_NAME(Obj3DD4* o) {
    ObjFAF38* c;

    if (--o->unk7C == 0) {
        silence_sound(2, 0x26);
        c = func_8002D1A4();
        if (c != 0) {
            play_sound(2, 0x25, o);
            c->unk0 = 0x41;
            c->unk1 = 0x10;
            c->unk2 = 3;
            c->unk7C = o;
        }
        if (o->unk15 != 0) {
            o->unk20 = 0x20000;
        } else {
            o->unk20 = -0x20000;
        }
        o->unk6++;
    }
    animate_object(o);
    apply_object_motion(o);
}
