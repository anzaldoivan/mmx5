#include "types.h"

extern u8 D_800FB75C_ovl10[][8];

extern void func_8002DF54(Ent299C*);
extern s32 func_800F2C4C_ovl10(Ent299C*, s32);

void func_800F299C_ovl10(Ent299C* e) {
    s32 r;
    u8* p;
    s32 t;
    s32 y;

    func_8002DF54(e);
    r = func_800F2C4C_ovl10(e, 2);
    switch (r) {
    case 2:
        e->unk5 = D_800FB75C_ovl10[e->unk90][6];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][2];
        p = e->unk68;
        e->unk6 = 0;
        e->unk5 = t;
        y = e->unkA;
        e->unkA = (-(e->unkA + (signed char)p[0] + p[2]) & 0xF) + y;
        break;
    }
}
