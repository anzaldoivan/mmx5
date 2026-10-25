/* Shared body (DK-5), from the banked draft of func_800EF4F8_ovl03 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800EC3B8.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32

M2C_UNK func_80017248();
M2C_UNK func_8002DF54();
s32 func_8002DFF8(void* arg0, s32 arg1, s32 arg2);
void func_8002E058(void*, s32);
extern s32 D_8009A0A0;
#define D_8009A0A0 (*(X4_Obj*)&D_8009A0A0)

void DEDUP_NAME(X4_Obj* self) {
    X4_Obj* pl;
    s32 v;
    s32 dx;

    func_80017248();
    func_8002DF54(self);
    pl = &D_8009A0A0;
    func_8002E058(
        self,
        func_8002DFF8(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_vel.val + self->x_vel.val / 2;
    self->x_vel.val = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
#undef D_8009A0A0
