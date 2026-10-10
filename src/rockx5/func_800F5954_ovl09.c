#include "types.h"

typedef struct Ent5954 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x95 - 7];
    u8 unk95;
    u8 unk96;
    u8 unk97;
} Ent5954;

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
