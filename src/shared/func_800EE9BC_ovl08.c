/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800EA704.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#define PLAYER (*(X4_Obj*)&g_Player)

void func_800EE9BC_ovl08(X4_Obj* self) {
    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 3) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x83) != 0) {
        M2C_FIELD(self, u8*, 0x83)--;
        return;
    }
    if ((self->y_pos.i.hi - PLAYER.y_pos.i.hi >= 0
             ? self->y_pos.i.hi - PLAYER.y_pos.i.hi
             : PLAYER.y_pos.i.hi - self->y_pos.i.hi) < 0x28) {
        if (self->unk15 != 0) {
            if (PLAYER.x_pos.i.hi < self->x_pos.i.hi + 0x50) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        } else {
            if (self->x_pos.i.hi - 0x50 < PLAYER.x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        }
        if (M2C_FIELD(self, u8*, 0x81) >= 0x3D) {
            self->unk5 = 4;
            self->unk6 = 0;
            ((s32(*)())set_animation)(self, 7);
            M2C_FIELD(self, u8*, 0x81) = 0;
            M2C_FIELD(self, u8*, 0x80) |= 2;
        }
    } else {
        M2C_FIELD(self, u8*, 0x81) = 0;
    }
}
