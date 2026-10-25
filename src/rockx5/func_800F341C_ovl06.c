/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004672C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_main, AGPL-3.0; proven shared with X6 by exact signature e7d22a6ee35c (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define NULL ((void*)0)
#define OBJECT_HEADER(object) ((X4_Obj*)(object))
#define M2C_UNK s32
extern u8 D_800FE48C_ovl06[][4];
extern u8 D_800FE4A8_ovl06[8];
extern u8 D_800FE4B0_ovl06[8];
M2C_UNK func_8002D6FC();

void func_800F341C_ovl06(X4_Obj* self) {
    s8 index;
    s8 event;
    u16 timer;
    X4_Obj* owner;

    owner = M2C_FIELD(self, X4_Obj**, 0x7C);
    self->x_pos.i.hi = (s16)(u16)owner->x_pos.i.hi;
    self->y_pos.i.hi = (s16)(u16)owner->y_pos.i.hi;
    M2C_FIELD(self, s8*, 0x45) = (M2C_FIELD(owner, s8*, 0x45) >> 4) & 0xF;
    if (self->unk2 != 0) {
        timer = --M2C_FIELD(self, u16*, 0x88);
        if ((timer << 16) == 0) {
            M2C_FIELD(self, u16*, 0x88) = 6;
            self->unk64 = (u8)self->unk64 + 1;
        }
    }
    index = self->unk2;
    if ((D_800FE4A8_ovl06[index] == owner->unk17) &&
        (D_800FE4B0_ovl06[index] == owner->unk5) && (owner->state == 1)) {
        event = M2C_FIELD(self, s8*, 0x45);
        if (event == 0) {
            self->unk50 = NULL;
            return;
        }
        self->unk50 = &D_800FE48C_ovl06[event];
        return;
    }
    func_8002D6FC(OBJECT_HEADER(self));
}
