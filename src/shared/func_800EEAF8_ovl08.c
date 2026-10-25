/* Shared body (DK-5), from the banked draft of func_800EEAF8_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EA840.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800171E8(void*, M2C_UNK);
s32 func_8003157C(void*, s16, s16);

void DEDUP_NAME(X4_Obj* self) {
    s16 x;

    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0x70) & 8)) {
        func_800171E8(self, 3);
        self->unk5 = 2;
        M2C_FIELD(self, s32*, 0x2C) = 0x4200;
        self->unk6 = 0;
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x28) = 0;
        M2C_FIELD(self, s8*, 0x67) = -1;
        return;
    }
    if (self->unk15 != 0) {
        u8* q = M2C_FIELD(self, u8**, 0x68);

        x = self->x_pos.i.hi + (s8)q[0] + q[2];
    } else {
        u8* q = M2C_FIELD(self, u8**, 0x68);

        x = (self->x_pos.i.hi - (s8)q[0]) - q[2];
    }
    if (func_8003157C(
            self, x,
            M2C_FIELD(self, u8**, 0x68)[3] +
                (self->y_pos.i.hi + (s8)M2C_FIELD(self, u8**, 0x68)[1]) + 8) &
        0xFF) {
        return;
    }
    if (self->unk2 == 1) {
        self->unk15 = (self->unk15 == 0) << 6;
        M2C_FIELD(self, s32*, 0x20) = -M2C_FIELD(self, s32*, 0x20);
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0x70) & 3)) {
        s32 v;

        func_800171E8(self, 2);
        self->unk5 = 5;
        self->unk6 = 0;
        M2C_FIELD(self, s32*, 0x24) = 0x38000;
        v = -0x10000;
        M2C_FIELD(self, s32*, 0x2C) = 0x4200;
        if (self->unk15 != 0) {
            v = 0x10000;
        }
        M2C_FIELD(self, s32*, 0x20) = v;
        M2C_FIELD(self, s8*, 0x67) = 1;
    }
}
