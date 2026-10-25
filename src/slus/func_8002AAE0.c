#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002AAE0(X4_BackgroundObj* arg0) {
    X4_BackgroundObj* bg = D_8009A1F8;
    s32 x = (bg->x_pos.i.hi >> 1) + arg0->unk40;

    arg0->x_pos.i.hi = x;
    arg0->y_pos.i.hi = bg->y_pos.i.hi + arg0->unk42;
}
