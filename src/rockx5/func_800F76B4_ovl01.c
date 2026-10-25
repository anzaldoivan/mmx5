#include "types.h"

void func_800F76B4_ovl01(Ent800FE04C* e) {
    e->unk20 = 0;
    e->unk24 = 0x28000;
    *(s32*)((u8*)e + 0x28) = 0;
    *(s32*)((u8*)e + 0x2C) = 0;
    e->unk6++;
}
