#include "types.h"
#include "mmx5/graphics.h"

void func_800F6E48_ovl26(Ent6E48* o) {
    o->unk16 = 4;
    o->unk3 = 1;
    switch (o->unk2) {
    case 0:
    case 2:
        o->unk16 = 5;
        set_animation(o, 0xB);
        break;
    case 4:
        o->unk16 = 5;
        set_animation(o, 9);
        break;
    case 6:
        o->unk16 = 5;
        set_animation(o, 0xA);
        break;
    case 1:
    case 3:
        o->unk16 = 3;
        set_animation(o, 8);
        break;
    case 5:
        o->unk16 = 3;
        set_animation(o, 6);
        break;
    case 7:
        o->unk16 = 3;
        set_animation(o, 7);
        break;
    case 16:
        o->unk15 = 0;
        set_animation(o, 0x12);
        o->unk16 = 4;
        o->unk3 = 0;
        break;
    case 17:
        o->unk15 = 0;
        set_animation(o, 0x13);
        o->unk16 = 4;
        o->unk3 = 0;
        break;
    case 18:
    case 19:
        set_animation(o, 0x14);
        o->unk16 = 4;
        o->unk3 = 0;
        break;
    }
    o->unk4 = 1;
    o->unk5 = 0;
    o->unk6 = 0;
}
