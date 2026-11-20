#include "types.h"

extern void (*D_80102D44_ovl04[])(Ent800FE23C*);
extern u8 D_800D1C2A;

void func_800FF0F0_ovl04(Ent800FE23C* self) {
    u8 state = self->unk5;
    Ent800FE23CParent* parent = self->unk80;

    self->unk8E = state;
    self->unkA = parent->unkA + self->unk88;
    self->unkE = parent->unkE + self->unk8A;
    D_80102D44_ovl04[(s8)state](self);
    if (D_800D1C2A & 4) {
        self->unk4++;
    }
}
