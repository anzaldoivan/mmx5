#include "types.h"

// from rockx5 800F1818
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xA - 7];
    u16 unkA;
    u8 padC[0x68 - 0xC];
    u8* unk68;
    u8 pad6C[0x8F - 0x6C];
    u8 unk8F;
} Ent1818;

extern u8 D_800FAB34_ovl09[][8];

extern void func_8002DF54(Ent1818*);
extern s32 func_800F1B40_ovl09(Ent1818*, s32);

void func_800F1818_ovl09(Ent1818* e) {
    s32 r;
    u8* p;
    s32 t;
    s32 y;

    func_8002DF54(e);
    r = func_800F1B40_ovl09(e, 2);
    switch (r) {
    case 2:
        e->unk5 = D_800FAB34_ovl09[e->unk8F][6];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FAB34_ovl09[e->unk8F][2];
        p = e->unk68;
        e->unk6 = 0;
        e->unk5 = t;
        y = e->unkA;
        e->unkA = (-(e->unkA + (signed char)p[0] + p[2]) & 0xF) + y;
        break;
    }
}
