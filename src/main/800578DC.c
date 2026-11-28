#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/system.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053D18.c, AGPL-3.0 (THIRD_PARTY.md). */
#define NULL ((void*)0)

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80093F70;

void func_800578DC(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    random_byte();
    M2C_FIELD(arg0, u16*, 0x1C) = (u16)(D_80093F70 & 0xFFF);
    temp_v0 = ((void* (*)())alloc_class6_slot)();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8*, 0) = 1;
        M2C_FIELD(temp_v0, s8*, 1) = 4;
        M2C_FIELD(temp_v0, u16*, 8) = (u16)M2C_FIELD(arg0, u16*, 0x1C);
        M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_2 = ((void* (*)())alloc_class6_slot)(temp_v0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s8*, 0) = 1;
        M2C_FIELD(temp_v0_2, s8*, 1) = 4;
        M2C_FIELD(temp_v0_2, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0x555) & 0xFFF);
        M2C_FIELD(temp_v0_2, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_2, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    temp_v0_3 = ((void* (*)())alloc_class6_slot)(temp_v0_2);
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, s8*, 0) = 1;
        M2C_FIELD(temp_v0_3, s8*, 1) = 4;
        M2C_FIELD(temp_v0_3, s16*, 8) =
            (s16)((M2C_FIELD(arg0, u16*, 0x1C) + 0xAAA) & 0xFFF);
        M2C_FIELD(temp_v0_3, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0_3, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
    }
    M2C_FIELD(arg0, s16*, 0x14) = 8;
    M2C_FIELD(arg0, s8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
#undef NULL
#undef M2C_FIELD

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053E44.c, AGPL-3.0 (THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

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
            q = alloc_class6_slot();
            if (q != 0) {
                M2C_FIELD(q, s8*, 0x0) = 1;
                M2C_FIELD(q, s8*, 0x1) = 4;
                random_byte();
                M2C_FIELD(q, u16*, 0x8) = D_80093F70 & 0xFFF;
                M2C_FIELD(q, u16*, 0xA) = self->x_pos.u.hi;
                M2C_FIELD(q, u16*, 0xE) = self->y_pos.u.hi;
            }
        }
    } else {
        self->state++;
        q2 = alloc_class6_slot();
        if (q2 != 0) {
            M2C_FIELD(q2, s8*, 0x0) = 1;
            M2C_FIELD(q2, s8*, 0x1) = 8;
            M2C_FIELD(q2, u16*, 0xA) = self->x_pos.u.hi;
            M2C_FIELD(q2, u16*, 0xE) = self->y_pos.u.hi;
        }
        *(u16*)((u8*)self + 0x14) = 10;
    }
}
#undef M2C_FIELD

void func_80057B28(u8* a0) {
    if ((g_playthrough_state.s[0xC] == 12 && g_playthrough_state.s[0x31] == 2 &&
         g_playthrough_state.s[0x1D] == 0x15) ||
        g_playthrough_state.s[0xC] == 0) {
        if (--*(u16*)(a0 + 0x14) == 0xFFFF) {
            g_playthrough_state.s[0xF] = 0x40;
        }
    } else {
        if (--*(u16*)(a0 + 0x14) == 0xFFFF) {
            a0[4]++;
        }
    }
}

void func_80057BD4(u8* p) {
    (*(u16*)(p + 0x14))++;
    if (*(u16*)(p + 0x14) % 5 == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            p[4]++;
        }
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053FE4.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_UNK s32

extern s8 D_800D1C1C;

void func_80057C60(void) {
    D_800D1C1C = 1;
    ((M2C_UNK(*)())clear_object_slot)();
}
