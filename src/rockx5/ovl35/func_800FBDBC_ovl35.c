#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_800FFC58_ovl35;
extern s16 D_800FFC5A_ovl35;
extern s16 D_800FFC5C_ovl35;

void func_800FBDBC_ovl35(Obj3DD4* o) {
    ObjFAF38* c;

    if (o->unk15 == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FFC5A_ovl35) {
                o->unkA = D_800FFC5A_ovl35;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FFC5A_ovl35) {
                o->unkA = D_800FFC5A_ovl35;
                o->unk20 = 0;
            }
        }
    } else {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FFC58_ovl35) {
                o->unkA = D_800FFC58_ovl35;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FFC58_ovl35) {
                o->unkA = D_800FFC58_ovl35;
                o->unk20 = 0;
            }
        }
    }
    if (o->unk24 > 0) {
        if (o->unkE <= D_800FFC5C_ovl35) {
            o->unkE = D_800FFC5C_ovl35;
            o->unk24 = 0;
        }
    } else if (o->unk24 < 0) {
        if (o->unkE >= D_800FFC5C_ovl35) {
            o->unkE = D_800FFC5C_ovl35;
            o->unk24 = 0;
        }
    }
    if ((o->unkA == D_800FFC5A_ovl35 && o->unk15 == 0) ||
        (o->unkA == D_800FFC58_ovl35 && o->unk15 == 0x40)) {
        if (o->unkE == D_800FFC5C_ovl35) {
            c = func_8002D1A4();
            if (c != 0) {
                play_sound(2, 0x26, o);
                c->unk0 = 0x41;
                c->unk1 = 0x10;
                c->unk2 = 4;
                c->unk7C = o;
            }
            set_animation(o, 6);
            o->unk7C = 0x35;
            o->unk6++;
        }
    }
    animate_object(o);
    apply_object_motion(o);
}
