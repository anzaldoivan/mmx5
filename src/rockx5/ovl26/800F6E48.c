#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

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

void func_800F6F98_ovl26(u8* obj) {
    u8* g;

    if (*(s8*)(*(u8**)(obj + 0x50) + 4) == 2 ||
        (g = g_Player, ((s8*)g)[0xD4] != 0)) {
        obj[4] = 2;
        obj[5] = 0;
        obj[6] = 0;
        obj[3] = 0;
        return;
    }
    if (g[0xF7] == 0) {
        animate_object(obj);
    }
    if (*(s8*)(obj + 2) >= 0x10) {
        obj[3] = 1;
        switch (*(s8*)(obj + 2)) {
        case 16:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA) - 0x18;
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE);
            break;
        case 17:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA) + 0x18;
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE);
            break;
        case 18:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA);
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE) - 0x78;
            break;
        case 19:
            *(u16*)(obj + 0xA) = *(u16*)(*(u8**)(obj + 0x54) + 0xA);
            *(u16*)(obj + 0xE) = *(u16*)(*(u8**)(obj + 0x54) + 0xE) + 0x78;
            break;
        }
    }
}
