/* Adapted from sozud/mmx4 @29b62af src/main/objects.c:func_8002B1E8 (is_off_screen), AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

s32 func_8002D938(X4_Obj* self, s32 x_offset, s32 y_offset) {
    s16 x_pos;
    s16 y_pos;

    if (self->bg_offset < 0) {
        x_pos = self->x_pos.i.hi;
        y_pos = self->y_pos.i.hi;
    } else {
        x_pos = self->x_pos.i.hi - D_8009A1F8[self->bg_offset].x_pos.i.hi;
        y_pos = self->y_pos.i.hi - D_8009A1F8[self->bg_offset].y_pos.i.hi;
    }
    if ((u16)(x_pos + x_offset) < (u16)((x_offset << 1) + 0x140) &&
        (u16)(y_pos + y_offset) < (u16)((y_offset << 1) + 0xF0)) {
        return 0;
    }
    return 1;
}
