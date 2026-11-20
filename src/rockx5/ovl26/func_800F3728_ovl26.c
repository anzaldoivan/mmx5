#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F3728_ovl26(Ent3804* o) {
    animate_object(o);
    move_object(o);
    if (o->unk20 < 0) {
        if (o->unkA <= 0x910 - D_800F9F24_ovl26[o->unk94][o->unk2].hi) {
            o->unkA = 0x910 - D_800F9F24_ovl26[o->unk94][o->unk2].hi;
            set_animation(o, 0);
            o->unk6++;
        }
    } else if (o->unkA >= D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0xA10) {
        o->unkA = D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0xA10;
        set_animation(o, 0);
        o->unk6++;
    }
}
