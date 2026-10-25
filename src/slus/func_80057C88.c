/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8005400C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_27_teleport_intro.c:teleport_intro_spawn_quads, AGPL-3.0; proven shared with X6 by exact signature 6c6bde588dbe (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_8002DF78(void);
#define NULL ((void*)0)
struct X4_QuadObj* func_8002D53C(void);

void func_80057C88(ObjEEBEC* self) {
    struct X4_QuadObj* X4_f32;
    u32 var_i;

    switch (self->unk5) {
    case 0:
        X4_f32 = func_8002D53C();
        if (X4_f32 != NULL) {
            M2C_FIELD(X4_f32, s8*, 0x0) = 0x81;
            M2C_FIELD(X4_f32, s8*, 0x1) = 7;
            X4_f32->unk2 = 0;
            M2C_FIELD(X4_f32, ObjEEBEC**, 0x58) = self;
        }
        self->unk5 = 1;
        self->unk14++;
        return;
    case 1:
        var_i = 0;
        // spawn blue quads behind "READY"
        if (self->unk14 == 0) {
            self->unk14 = 0;
            do {
                X4_f32 = func_8002D53C();
                if (X4_f32 != NULL) {
                    M2C_FIELD(X4_f32, s8*, 0x0) = 0x81;
                    M2C_FIELD(X4_f32, s8*, 0x1) = 7;
                    X4_f32->unk2 = 1;
                    M2C_FIELD(X4_f32, s8*, 0x7) = var_i;
                    M2C_FIELD(X4_f32, ObjEEBEC**, 0x58) = self;
                    self->unk14++;
                }
                var_i += 1;
            } while (var_i < 0xA);
            self->unk5 = 2;
            return;
        }
        return;
    case 2:
        var_i = 0;
        if (self->unk14 == 0) {
            self->unk14 = 0;
            do {
                X4_f32 = func_8002D53C();
                if (X4_f32 != NULL) {
                    M2C_FIELD(X4_f32, s8*, 0x0) = 0x81;
                    M2C_FIELD(X4_f32, s8*, 0x1) = 7;
                    X4_f32->unk2 = 2;
                    M2C_FIELD(X4_f32, s8*, 0x7) = func_8002DF78() & 3;
                    M2C_FIELD(X4_f32, ObjEEBEC**, 0x58) = self;
                    self->unk14++;
                }
                var_i += 1;
            } while (var_i < 8);
            self->unk5 = 3;
            return;
        }
        break;
    case 3:
        if (self->unk14 == 0) {
            self->unk14 = 0;
            M2C_FIELD(self, u8*, 0x16) = 1;
        }
        break;
    }
}
