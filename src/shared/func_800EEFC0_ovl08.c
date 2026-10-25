/* Shared body (DK-5), from the banked draft of func_800EEFC0_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EAD08.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK DEDUP_CALLEE(void*, M2C_UNK);
extern M2C_UNK D_800750C0;
extern M2C_UNK D_8009A0A0;
extern M2C_UNK D_800F39D8_ovl08;
extern M2C_UNK D_800F39DC_ovl08;
extern M2C_UNK D_800F39E4_ovl08;
extern M2C_UNK D_800F3ADC_ovl08;

void DEDUP_NAME(void* arg0) {
    X4_Obj* self = arg0;
    s32 x;
    s32 f;
    s32 m;
    self->state++;
    self->unk5 = 1;
    x = self->x_pos.val;
    self->bg_offset = (*(X4_Obj*)&D_8009A0A0).bg_offset;
    self->unk18.val = x;
    self->unk1C.val = self->y_pos.val;
    f = ((*(X4_Obj*)&D_8009A0A0).x_pos.val >= x) << 6;
    self->animation_table = (u32**)&D_800F3ADC_ovl08;
    self->unk16 = 6;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F39D8_ovl08;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F39E4_ovl08;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F39DC_ovl08;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800750C0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 1;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    M2C_FIELD(arg0, u8*, 0x80) = 0;
    M2C_FIELD(arg0, u8*, 0x82) = 0;
    M2C_FIELD(arg0, u8*, 0x81) = 0;
    M2C_FIELD(arg0, u8*, 0x83) = 0;
    self->unk15 = f;
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 2) < 2U) {
        self->state = 3;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        m = -0x10;
        self->x_pos.u.hi = (self->x_pos.u.hi & m) + 8;
        self->y_pos.u.hi = (self->y_pos.u.hi & m) + 0x14;
        DEDUP_CALLEE(arg0, 0);
    } else {
        DEDUP_CALLEE(arg0, 1);
    }
}
