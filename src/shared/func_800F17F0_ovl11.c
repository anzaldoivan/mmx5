/* Shared body (DK-5), from the banked draft of func_800F17F0_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_22/func_800F461C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
void func_800F1B3C_ovl11(void*);

extern M2C_UNK D_80074F80;
extern u8 D_800F9924_ovl11[];
extern u8 D_800F992C_ovl11[];

void DEDUP_NAME(X4_Obj* self) {
    X4_Obj* parent;
    s8 kind;

    self->state++;
    self->on_screen = 1;
    self->hp = 1;
    self->unk60 = 6;
    self->unk50 = D_800F9924_ovl11;
    self->unk58 = &D_80074F80;
    self->unk68 = (void*)D_800F992C_ovl11;
    self->unk54 = D_800F9924_ovl11;
    kind = self->unk2;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    self->unk42 &= 0x7FFF;
    parent = M2C_FIELD(self, X4_Obj**, 0x7C);
    if (kind == 0) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x20;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x20;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi - 8;
    } else if (kind == 1) {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0x1D;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0x1D;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0xE;
    } else {
        if (self->unk15 == 0) {
            self->x_pos.i.hi = parent->x_pos.i.hi - 0xC;
        } else {
            self->x_pos.i.hi = parent->x_pos.i.hi + 0xC;
        }
        self->y_pos.i.hi = parent->y_pos.i.hi + 0x12;
    }
    func_800171E8(self, 3);
    func_800F1B3C_ovl11(self);
    M2C_FIELD(self, s32*, 0x84) = 0x10;
    M2C_FIELD(self, s32*, 0x8C) = 0;
}
