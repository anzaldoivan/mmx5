#include "types.h"
#include "mmx5/globals.h"

void func_8002A908(X4_BackgroundObj* arg0) {
    X4_BackgroundObj* bg = D_8009A1F8.bg;

    arg0->x_pos.i.hi = bg->x_pos.i.hi + arg0->unk40;
    arg0->y_pos.i.hi = bg->y_pos.i.hi + arg0->unk42;
}

#define D_800EEC60_ovl00 func_8002A93C
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

void func_8002A944(u8* p) {
    *(s16*)(p + 0xE) = D_8009A206.s + *(s16*)(p + 0x42);
}
