#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"

void func_800F27C4_ovl10(u8* obj) {
    if (obj[0x90] == 0) {
        set_animation(obj, 11);
        obj[0x15] = 0x40;
    } else {
        set_animation(obj, 11);
        obj[0x15] = 0;
    }
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = -0x13000;
    obj[6]++;
}

extern u8 D_800FB75C_ovl10[][8];

extern s32 func_800F2C4C_ovl10(Ent26B4*, s32);

void func_800F2834_ovl10(Ent26B4* e) {
    s32 r;
    u8* p;
    s32 t;
    u16 y;

    move_object(e);
    r = func_800F2C4C_ovl10(e, 3);
    switch (r) {
    case 2:
        e->unk5 = D_800FB75C_ovl10[e->unk90][7];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][3];
        p = e->unk68;
        y = e->unkE;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkE = y - ((y + (signed char)p[1] - p[3]) & 0xF);
        if (t & 0xF0) {
            e->unk5 = t & 0xF;
            e->unk90 ^= 1;
        }
        break;
    }
}
