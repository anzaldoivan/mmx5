#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0xA - 7];
    u16 unkA;
    u8 padC[0x68 - 0xC];
    u8* unk68;
    u8 pad6C[0x8C - 0x6C];
    u8 unk8C;
} EntFE308;

extern u8 D_800FFFA4_ovl34[][8];

extern void func_80017248(EntFE308*);
extern void func_8002DF54(EntFE308*);
extern s32 func_800FEF10_ovl34(EntFE308*, s32);

void func_800FE308_ovl34(EntFE308* e) {
    s32 r;
    u8* p;
    u16 y;
    s32 t;

    func_80017248(e);
    func_8002DF54(e);
    r = func_800FEF10_ovl34(e, 0);
    switch (r) {
    case 2:
        e->unk5 = D_800FFFA4_ovl34[e->unk8C][4];
        e->unk6 = 0;
        break;
    case 1:
        t = D_800FFFA4_ovl34[e->unk8C][0];
        p = e->unk68;
        y = e->unkA;
        e->unk6 = 0;
        e->unk5 = t;
        e->unkA = y - ((y + (signed char)p[0] - p[2]) & 0xF);
        break;
    }
}
