#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002D9EC(X4_Obj* self, s32 x_offset, s32 y_offset) {
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
    if ((u16)(x_pos + x_offset) < (u16)(x_offset + 0x140 + x_offset) &&
        (u16)(y_pos + y_offset) < (u16)(y_offset + 0xF0 + y_offset)) {
        self->on_screen = 1;
    }
}
