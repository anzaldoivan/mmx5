#include "types.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

void func_800F7534_ovl26(u8* a0) {
    u16 v;

    move_object(a0);
    v = *(u16*)(*(u8**)(a0 + 0x7C) + 0x80);
    a0[6]++;
    *(u16*)(a0 + 0x88) = v;
}

void func_800F7570_ovl26(u8* a0) {
    move_object(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[6]++;
    }
}

void func_800F75C0_ovl26(u8* obj) {
    s8 state = ((s8*)obj)[2];

    if ((state == 0 || state == 2) && ((s8*)obj)[0x45] != 0) {
        set_animation(obj, 0x11);
    }
}
