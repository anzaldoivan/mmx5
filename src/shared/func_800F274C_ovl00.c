#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F274C_ovl00(u8* obj) {
    D_1F80004C.s8s[0x89] = 1;
    D_1F80004C.s8s[0x80] = -0x40;
    D_1F80004C.s8s[0x81] = 4;
    D_1F80004C.s8s[0x82] = 0x18;
    D_1F80004C.s8s[0x83] = 0x10;
    set_animation(obj, 3);
    obj[6]++;
}

void func_800F2038_ovl00(ObjFE130* self);

void func_800F27C8_ovl00(ObjFE130* self) {
    D_1F80004C.scr0b1c->unk80 = -0x40 - self->unk45;
    if (self->unk45 == 1) {
        /* 0x89 lies past Scr0B1C's proven fields */
        ((u8*)D_1F80004C.scr0b1c)[0x89] = 0;
        func_800F2038_ovl00(self);
    }
}
