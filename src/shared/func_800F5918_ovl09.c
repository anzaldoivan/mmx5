#include "types.h"
#include "mmx5/graphics.h"

void func_800F5918_ovl09(u8* obj) {
    set_animation(obj, 0);
    obj[0x95] = 0x3C;
    obj[6]++;
}

extern u8 D_800FAD58_ovl09[][6];

void func_800F5954_ovl09(Ent5954* e) {
    if (e->unk95 == 0) {
        e->unk5 = D_800FAD58_ovl09[e->unk96][e->unk97];
        e->unk6 = 0;
        e->unk97++;
    } else {
        e->unk95--;
    }
}
