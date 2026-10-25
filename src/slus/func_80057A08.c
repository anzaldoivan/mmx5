/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053E44.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define M2C_UNK s32

struct X4_QuadObj* func_8002D53C(void);
s32 func_8002DF78();
s32 func_8002DFB0();
void func_8004FE6C();
extern u16 D_80093F70;

void func_80057A08(X4_Obj* self) {
    struct X4_QuadObj* q;
    struct X4_QuadObj* q2;
    // !FAKE: pins c to $2; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 c asm("$2");
    s32 t;

    c = *(u16*)((u8*)self + 0x14);
    if (c != 0) {
        *(u16*)((u8*)self + 0x14) = c - 1;
        t = *((u8*)self + 0x16) - 1;
        *((u8*)self + 0x16) = t;
        if ((t << 24) == 0) {
            *((u8*)self + 0x16) = 4;
            func_8004FE6C(self, 1, 0x60, 0x60, 2);
        }
        if (!(func_8002DFB0() & 1)) {
            q = func_8002D53C();
            if (q != 0) {
                M2C_FIELD(q, s8*, 0x0) = 1;
                M2C_FIELD(q, s8*, 0x1) = 4;
                func_8002DF78();
                M2C_FIELD(q, u16*, 0x8) = D_80093F70 & 0xFFF;
                M2C_FIELD(q, u16*, 0xA) = self->x_pos.u.hi;
                M2C_FIELD(q, u16*, 0xE) = self->y_pos.u.hi;
            }
        }
    } else {
        self->state++;
        q2 = func_8002D53C();
        if (q2 != 0) {
            M2C_FIELD(q2, s8*, 0x0) = 1;
            M2C_FIELD(q2, s8*, 0x1) = 8;
            M2C_FIELD(q2, u16*, 0xA) = self->x_pos.u.hi;
            M2C_FIELD(q2, u16*, 0xE) = self->y_pos.u.hi;
        }
        *(u16*)((u8*)self + 0x14) = 10;
    }
}
