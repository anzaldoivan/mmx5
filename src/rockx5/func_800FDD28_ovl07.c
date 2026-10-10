#include "types.h"

extern void (*D_80101E90_ovl07[])(Ovl07Ent*);

void func_800FDD28_ovl07(Ovl07Ent* e) {
    if (e->unk8E != 0 && ((Ovl07Ent*)e->unk7C)->unk8E == 2) {
        e->unk20 = -0x18000;
        e->unk24 = 0;
        e->unk8E = 0;
        e->unk5 = 6;
        e->unk6 = 0;
        return;
    }
    D_80101E90_ovl07[e->unk6](e);
}
