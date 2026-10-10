#include "types.h"

typedef struct Ent79F0 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x91 - 7];
    u8 unk91;
    u8 unk92;
    u8 unk93;
} Ent79F0;

extern u8 D_800FA0BC_ovl03[][6];

void func_800F79F0_ovl03(Ent79F0* e) {
    if (e->unk91 == 0) {
        u8 t;
        t = D_800FA0BC_ovl03[e->unk92][e->unk93];
        e->unk6 = 0;
        e->unk93++;
        e->unk5 = t;
    } else {
        e->unk91--;
    }
}
