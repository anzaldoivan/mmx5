#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

void func_800F76B4_ovl01(Ent800FE04C* e) {
    e->unk20 = 0;
    e->unk24 = 0x28000;
    *(s32*)((u8*)e + 0x28) = 0;
    *(s32*)((u8*)e + 0x2C) = 0;
    e->unk6++;
}

void func_800F76DC_ovl01(u8* a0) {
    s32 r;

    move_object(a0);
    r = is_off_screen(a0, 0x300, 0x20);
    if (r == 1) {
        a0[5] = r;
        a0[6] = 0;
    }
}
