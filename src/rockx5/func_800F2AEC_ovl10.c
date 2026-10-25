#include "types.h"

extern u8 D_800FB75C_ovl10[][8];

extern void func_8002DF54(Ent299C*);
extern s32 func_800F2C4C_ovl10(Ent299C*, s32);

void func_800F2AEC_ovl10(Ent299C* e) {
    s32 r;
    u8* p;
    s32 t;
    u16 y;

    func_8002DF54(e);
    r = func_800F2C4C_ovl10(e, 0);
    switch (r) {
    case 2:
        e->unk5 = D_800FB75C_ovl10[e->unk90][4];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][0];
        p = e->unk68;
        y = e->unkA;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkA = y - ((y + (signed char)p[0] - p[2]) & 0xF);
        break;
    }
}
