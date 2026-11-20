/* Shared body (DK-5), from the banked draft of func_800FA474_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FD5AC_ovl01[];
extern u8 D_800FD5A8_ovl01[];

void DEDUP_NAME(X4_Obj* self) {
    s8 v;

    animate_object(self);
    v = *(s8*)&self->pad44[1];
    if (v == 1) {
        self->unk60 = 6;
        self->x_vel.val = 0;
        self->unk28 = 0;
        self->y_vel.val = 0x60000;
        self->unk2C = 0xE00;
        set_animation(self, 0xE);
        self->unk54 = D_800FD5AC_ovl01;
        self->unk50 = D_800FD5A8_ovl01;
        self->unk68 = 0;
        self->unk6 = v;
    }
}
