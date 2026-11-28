#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
extern u8 D_80101CEC_ovl04[];

void func_800F6D44_ovl04(Obj6D44* e) {
    e->unk3 = 0;
    if (--e->unk8F == 0) {
        e->unk68 = D_80101CEC_ovl04;
        e->unk20 = 0;
        e->unk24 = -e->unk24;
        e->unkE = 0x20;
        e->unkA = e->unk8C;
        if (e->unkA < D_8009A0AA) {
            e->unk91 = 0;
            e->unk15 = 0;
        } else {
            e->unk15 = 0x40;
            e->unk91 = 1;
        }
        set_animation(e, 0xB);
        e->unk88 = 0xE10;
        e->unk5 = 4;
        e->unk6 = 0;
    }
}
