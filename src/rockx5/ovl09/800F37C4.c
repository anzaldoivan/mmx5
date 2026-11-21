#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

#include "shared/func_800F37C4_ovl09.c"

extern s16 D_800FB620_ovl09;
extern s16 D_800FB622_ovl09;
extern s16 D_800FB624_ovl09;

void func_800F38B0_ovl09(Obj3DD4* o) {
    ObjFAF38* c;

    if (o->unk15 == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FB622_ovl09) {
                o->unkA = D_800FB622_ovl09;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FB622_ovl09) {
                o->unkA = D_800FB622_ovl09;
                o->unk20 = 0;
            }
        }
    } else {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800FB620_ovl09) {
                o->unkA = D_800FB620_ovl09;
                o->unk20 = 0;
            }
        } else if (o->unk20 > 0) {
            if (o->unkA >= D_800FB620_ovl09) {
                o->unkA = D_800FB620_ovl09;
                o->unk20 = 0;
            }
        }
    }
    if (o->unk24 > 0) {
        if (o->unkE <= D_800FB624_ovl09) {
            o->unkE = D_800FB624_ovl09;
            o->unk24 = 0;
        }
    } else if (o->unk24 < 0) {
        if (o->unkE >= D_800FB624_ovl09) {
            o->unkE = D_800FB624_ovl09;
            o->unk24 = 0;
        }
    }
    if ((o->unkA == D_800FB622_ovl09 && o->unk15 == 0) ||
        (o->unkA == D_800FB620_ovl09 && o->unk15 == 0x40)) {
        if (o->unkE == D_800FB624_ovl09) {
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
