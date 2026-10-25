/* Shared body (DK-5), from the banked draft of func_800F1650_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800ECA98.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern s32 D_800F98F0_ovl11[];
extern s32 D_800F98F8_ovl11[];

#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))

void DEDUP_NAME(X4_Obj* self) {
    u8 t;
    s32 c;
    // !FAKE: pins y to $5; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32 y asm("$5");
    // !FAKE: pins q to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register s32* q asm("$4");

    t = U8F(self, 0x8F);
    if (t == 0) {
        q = D_800F98F0_ovl11;
        self->x_vel.val = *(s32*)(((self->unk15 >> 4) & 4) + (u8*)q);
        y = D_800F98F8_ovl11[self->unk2 != 0];
        self->unk42 &= 0x7FFF;
        self->unk5++;
        self->y_vel.val = y;
        return;
    }
    U8F(self, 0x8F) = t - 1;
    c = U8F(self, 0x90) - 1;
    U8F(self, 0x90) = c;
    if ((c & 0xFF) == 0xFF) {
        U8F(self, 0x90) = 2;
        self->unk42 &= 0x7FFF;
        return;
    }
    self->unk42 |= 0x8000;
}
#undef U8F
