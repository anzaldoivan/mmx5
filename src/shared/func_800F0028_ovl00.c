#include "types.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F0028_ovl00(Obj4FE0* e) {
    s32 d;

    move_object(e);
    d = D_8009A0AA - e->unkA;
    if (d >= 0 ? d < 0x20 : e->unkA - D_8009A0AA < 0x20) {
        set_animation(e, 2);
        e->unk6++;
        D_1F80004C.scr->unk86 = (random_byte() & 7) + 1;
    }
}

#define G D_1F80004C.bytes

void func_800F00B8_ovl00(u8* obj) {
    move_object(obj);
    if (--G[0x86] == 0xFF) {
        obj[6]++;
    }
}

extern u8 D_800FA778_ovl00[];

void func_800F0118_ovl00(ObjFE130* obj) {
    if (obj->unk45 == 1) {
        obj->unk68 = D_800FA778_ovl00;
        obj->unk5 = 2;
        obj->unk6 = 0;
        D_1F80004C.scr1090->unk86 = 0x28;
    } else {
        move_object(obj);
    }
}
