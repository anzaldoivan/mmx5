#include "types.h"

extern u8 D_800FB75C_ovl10[][8];

extern void func_8002DF54(Ent26B4*);
extern s32 func_800F2C4C_ovl10(Ent26B4*, s32);

void func_800F26B4_ovl10(Ent26B4* e) {
    s32 r;
    u8* p;
    s32 t;
    s32 v;
    s32 y;

    func_8002DF54(e);
    r = func_800F2C4C_ovl10(e, 1);
    switch (r) {
    case 2:
        v = D_800FB75C_ovl10[e->unk90][5];
        e->unk6 = 0;
        e->unk5 = v;
        if (v & 0xF0) {
            e->unk5 = v & 0xF;
            e->unk90 ^= 1;
        }
        break;
    case 1:
        t = D_800FB75C_ovl10[e->unk90][1];
        p = e->unk68;
        e->unk6 = 0;
        e->unk5 = t;
        y = e->unkE;
        e->unkE = (-(e->unkE + (signed char)p[1] + p[3]) & 0xF) + y;
        break;
    }
}
