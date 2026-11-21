#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

void func_800F2940_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        set_animation(obj, 8);
        obj[0x15] = 0;
    } else {
        set_animation(obj, 8);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = -0x13000;
    *(s32*)(obj + 0x24) = 0;
    obj[6]++;
}

extern u8 D_800FB75C_ovl10[][8];

extern s32 func_800F2C4C_ovl10(Ent299C*, s32);

void func_800F299C_ovl10(Ent299C* e) {
    s32 r;
    u8* p;
    s32 t;
    s32 y;

    move_object(e);
    r = func_800F2C4C_ovl10(e, 2);
    switch (r) {
    case 2:
        e->unk5 = D_800FB75C_ovl10[e->unk90][6];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][2];
        p = e->unk68;
        e->unk6 = 0;
        e->unk5 = t;
        y = e->unkA;
        e->unkA = (-(e->unkA + (signed char)p[0] + p[2]) & 0xF) + y;
        break;
    }
}
