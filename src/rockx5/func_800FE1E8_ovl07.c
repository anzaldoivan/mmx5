#include "types.h"

extern void func_80017248(Ent800FE1E8*);
extern u8 D_80101DD0_ovl07[];
extern u8 D_80101DB8_ovl07[];
extern u8 D_80101DC4_ovl07[];

void func_800FE1E8_ovl07(Ent800FE1E8* o) {
    s32 v = o->unk45;

    if (v == 2) {
        o->unk68 = D_80101DD0_ovl07;
        o->unk50 = D_80101DB8_ovl07;
        o->unk54 = D_80101DC4_ovl07;
        o->unk8D = 1;
        o->unk15 = 0;
        o->unk8C = 1;
        o->unk5 = v;
        o->unk6 = 0;
    }
    func_80017248(o);
}
