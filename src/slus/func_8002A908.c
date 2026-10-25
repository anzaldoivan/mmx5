#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002A908(X4_BackgroundObj* arg0) {
    X4_BackgroundObj* bg = D_8009A1F8;

    arg0->x_pos.i.hi = bg->x_pos.i.hi + arg0->unk40;
    arg0->y_pos.i.hi = bg->y_pos.i.hi + arg0->unk42;
}
