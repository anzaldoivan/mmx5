#include "types.h"

#define G (*(u8**)0x1F80004C)

extern Obj4FE0 D_8009A0A0;
extern void func_800171E8(Obj4FE0*, s32);
extern s8 func_8002E024(Obj4FE0*, Obj4FE0*);
extern void func_800F09F0_ovl28(Obj4FE0*);

void func_800F1184_ovl28(Obj4FE0* s) {
    s->unk6++;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0;
    s->unk2C = 0;
    func_800171E8(s, 1);
    G[0x80] = 20;
    G[0x82] = 0;
    if (D_8009A0A0.unkA - s->unkA > 0) {
        s->unk15 = 0x40;
    }
    G[0x85] = func_8002E024(s, &D_8009A0A0);
    func_800F09F0_ovl28(s);
}
