/* Shared body (DK-5), from the banked draft of func_800F59D8_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

extern X4_Obj D_8009A0A0;

void DEDUP_NAME(X4_Obj* arg0) {
    s16 off;
    s16 x;
    s32 t;
    u8 v;

    D_1F80004C.bytes[0x86]++;
    off = arg0->y_pos.u.hi - (D_8009A0A0.y_pos.u.hi - 0x19);
    if (arg0->unk15 == 0) {
        t = off - 0x2C;
        x = arg0->x_pos.i.hi + t;
    } else {
        t = off - 0x2C;
        x = arg0->x_pos.i.hi - t;
    }
    if (ABS(D_8009A0A0.x_pos.i.hi - x) < 0x21) {
        v = 5;
    } else {
        v = 4;
    }
    arg0->unk5 = v;
    arg0->unk6 = 0;
}
