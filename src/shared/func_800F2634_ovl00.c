#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define G ((s8*)D_1F80004C.bytes)
void func_800F2634_ovl00(u8* obj) {
    set_animation(obj, 2);
    G[0x89] = 1;
    G[0x80] = -0x1A;
    G[0x81] = -0x18;
    G[0x82] = 0x18;
    G[0x83] = 0xE;
    obj[6]++;
}

void func_800F2038_ovl00(ObjFE130* self);

void func_800F26AC_ovl00(ObjFE130* self) {
    D_1F80004C.scr0b1c->unk80 = -0x1A - self->unk45;
    if (self->unk45 == 1) {
        /* 0x89 lies past Scr0B1C's proven fields */
        ((u8*)D_1F80004C.scr0b1c)[0x89] = 0;
        func_800F2038_ovl00(self);
    }
}
