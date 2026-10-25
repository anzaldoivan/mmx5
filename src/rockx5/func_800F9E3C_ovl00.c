#include "types.h"

extern u8 D_800FB650_ovl00[];
extern void func_800171E8(Obj9D50*, s32);

void func_800F9E3C_ovl00(Obj9D50* self) {
    Obj9D50* p = self->parent;

    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    self->unk30 = D_800FB650_ovl00;
    self->unk3C = p->unk3C;
    self->unk14 = 0;
    self->unk16 = 0x10;
    self->unk15 = 0;
    self->unk67 = 0;
    self->unk3 = 1;
    self->unk68 = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unkA = p->unkA - 0xA8;
    self->unkE = 0x144;
    self->unk5C = 1;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk60 = 8;
    func_800171E8(self, 0);
    self->state++;
}
