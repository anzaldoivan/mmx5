#include "types.h"
#include "mmx5/object.h"

void func_800F7534_ovl26(u8* a0) {
    u16 v;

    move_object(a0);
    v = *(u16*)(*(u8**)(a0 + 0x7C) + 0x80);
    a0[6]++;
    *(u16*)(a0 + 0x88) = v;
}
