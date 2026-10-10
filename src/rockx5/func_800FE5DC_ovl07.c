#include "types.h"

extern void func_800171E8(ObjFE130*, s32);
extern void func_80017248(ObjFE130*);
extern u8 D_80101DD0_ovl07[];
extern u8 D_80101DB8_ovl07[];
extern u8 D_80101DC4_ovl07[];

void func_800FE5DC_ovl07(ObjFE130* o) {
    s32 one = o->unk45;

    if (one == 1) {
        if (o->unk8D == 0) {
            /* ObjFE130 has no 0x0A field in types.h; raw offset */
            *(u16*)((u8*)o + 0xA) -= 12;
            func_800171E8(o, 14);
        }
        o->unk68 = D_80101DD0_ovl07;
        o->unk50 = D_80101DB8_ovl07;
        o->unk54 = D_80101DC4_ovl07;
        o->unk8D = one;
        o->unk15 = 0;
        if (o->unk88 == 0) {
            o->unk8C = 0;
            o->unk5 = 0;
        } else {
            o->unk8C = one;
            o->unk5 = one;
        }
        o->unk6 = 0;
    } else {
        func_80017248(o);
    }
}
