#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern X4_S16Pair D_800F9F24_ovl26[][16];

void func_800F3B10_ovl26(Ent3804* o) {
    animate_object(o);
    move_object(o);
    if ((*(u8**)((u8*)o + 0x7C))[0x96] == 0) {
        if (o->unk20 < 0) {
            if (o->unkA <= D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x910) {
                o->unkA = D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x910;
                set_animation(o, 0);
                o->unk6++;
            }
        } else {
            if (o->unkA >= 0xA50 - D_800F9F24_ovl26[o->unk94][o->unk2].hi) {
                o->unkA = 0xA50 - D_800F9F24_ovl26[o->unk94][o->unk2].hi;
                set_animation(o, 0);
                o->unk6++;
            }
        }
    } else if (o->unk20 < 0) {
        if (o->unkA <= D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x8D0) {
            o->unkA = D_800F9F24_ovl26[o->unk94][o->unk2].hi + 0x8D0;
            set_animation(o, 0);
            o->unk6++;
        }
    } else {
        if (o->unkA >= 0xA10 - D_800F9F24_ovl26[o->unk94][o->unk2].hi) {
            o->unkA = 0xA10 - D_800F9F24_ovl26[o->unk94][o->unk2].hi;
            set_animation(o, 0);
            o->unk6++;
        }
    }
}
