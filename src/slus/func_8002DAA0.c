#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002DAA0(X4_Obj* self) {
    s16 x_pos;
    s16 y_pos;

    self->on_screen = 0;
    if (self->bg_offset < 0) {
        x_pos = self->x_pos.i.hi;
        y_pos = self->y_pos.i.hi;
    } else {
        x_pos = self->x_pos.i.hi - D_8009A1F8[self->bg_offset].x_pos.i.hi;
        y_pos = self->y_pos.i.hi - D_8009A1F8[self->bg_offset].y_pos.i.hi;
    }
    if ((u16)(x_pos + 0x60) < 0x200 && (u16)(y_pos + 0x50) < 0x190) {
        self->on_screen = 1;
    }
}
