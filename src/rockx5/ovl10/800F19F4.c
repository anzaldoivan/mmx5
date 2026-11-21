#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/movement.h"

void func_800F19F4_ovl10(Obj3DD4* e) {
    set_animation(e, 3);
    if (D_8009A0AA <= e->unkA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    e->unk6++;
}

extern void func_800F1C64_ovl10(u8* arg0);

void func_800F1A50_ovl10(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0x29, 0);
        set_animation(obj, 4);
        func_800F1C64_ovl10(obj);
        obj[6]++;
    }
}

void func_800F1AB0_ovl10(u8* obj) {
    if (((s8*)obj)[0x45] == 1 && D_1F80004C.bytes[0x80] == 0) {
        set_animation(obj, 5);
        obj[6]++;
    }
}

void func_800F1B14_ovl10(u8* o) {
    if (*(s8*)(o + 0x45) == 2) {
        o[5] = 3;
        o[6] = 0;
    }
}

#include "shared/func_800F1B34_ovl10.c"
