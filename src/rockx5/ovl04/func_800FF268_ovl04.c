#include "types.h"

extern void (*D_80102D50_ovl04[])(Ent800FE23C*);
extern u8 D_800D1C2A;

void func_800FF268_ovl04(Ent800FE23C* self) {
    u8 state = self->unk5;
    Ent800FE23CParent* parent = self->unk80;

    self->unk8E = state;
    self->unkA = parent->unkA + 0x10;
    self->unkE = parent->unkE - 0x2A;
    D_80102D50_ovl04[(s8)state](self);
    if (D_800D1C2A & 8) {
        self->unk4++;
    }
}
