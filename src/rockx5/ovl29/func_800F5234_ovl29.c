#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s32 D_800F9898_ovl29[];

void func_800F5234_ovl29(Obj4EA0* e) {
    ((u8*)e)[0x60] = 8;
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    set_animation(e, 5);
    e->unk50 = D_800F9898_ovl29;
    e->unk6++;
}
