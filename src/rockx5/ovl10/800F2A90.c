#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

void func_800F2A90_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        set_animation(obj, 9);
        obj[0x15] = 0;
    } else {
        set_animation(obj, 9);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = 0x13000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}

extern u8 D_800FB75C_ovl10[][8];

extern s32 func_800F2C4C_ovl10(Ent299C*, s32);

void func_800F2AEC_ovl10(Ent299C* e) {
    s32 r;
    u8* p;
    s32 t;
    u16 y;

    move_object(e);
    r = func_800F2C4C_ovl10(e, 0);
    switch (r) {
    case 2:
        e->unk5 = D_800FB75C_ovl10[e->unk90][4];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][0];
        p = e->unk68;
        y = e->unkA;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkA = y - ((y + (signed char)p[0] - p[2]) & 0xF);
        break;
    }
}
