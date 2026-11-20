/* Shared body (DK-5), from the banked draft of func_800EF190_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

void DEDUP_NAME(X4_Obj* self) {
    s32 d;

    if ((u8)(self->unk5 - 5) < 2) {
        return;
    }
    d = g_Player_as_X4_Obj.y_pos.i.hi - self->y_pos.i.hi;
    if (d >= 0 ? d < 0x20
               : self->y_pos.i.hi - g_Player_as_X4_Obj.y_pos.i.hi < 0x20) {
        d = g_Player_as_X4_Obj.x_pos.i.hi - self->x_pos.i.hi;
        if (d >= 0 ? d < 0x60
                   : self->x_pos.i.hi - g_Player_as_X4_Obj.x_pos.i.hi < 0x60) {
            if (!(self->unk70 & 3)) {
                if (self->unk15 == 0
                        ? g_Player_as_X4_Obj.x_pos.val < self->x_pos.val
                        : g_Player_as_X4_Obj.x_pos.val > self->x_pos.val) {
                    self->unk80 = 1;
                }
            }
        }
    }
    if (self->unk5 == 2 && self->unk80 != 0) {
        self->unk5 = 4;
        self->unk6 = 0;
        self->x_vel.val = 0;
        self->unk28 = 0;
    }
}
