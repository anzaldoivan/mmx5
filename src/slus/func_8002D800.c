#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

s32 func_8002D800(X4_Obj* self) {
    s16 x_pos;
    s16 y_pos;

    if (self->bg_offset < 0) {
        x_pos = self->x_pos.i.hi;
        y_pos = self->y_pos.i.hi;
    } else {
        x_pos = self->x_pos.i.hi - D_8009A1F8[self->bg_offset].x_pos.i.hi;
        y_pos = self->y_pos.i.hi - D_8009A1F8[self->bg_offset].y_pos.i.hi;
    }
    if ((u16)(x_pos + 0x40) < 0x1C0 && (u16)(y_pos + 0x40) < 0x170) {
        return 0;
    }
    return 1;
}
