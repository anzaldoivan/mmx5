/* Shared body (DK-5), from the banked draft of func_80029304 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80028338.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
extern X4_BackgroundObj D_8009A1F8[3];

void DEDUP_NAME(X4_BackgroundObj* arg0) {
    u16 ref;
    s16 pos;
    s16 diff;
    u16 cur;
    u16 yref;
    s16 tmp;

    ref = (u16)arg0->unk14.i.hi;
    tmp = D_8009A1F8[0].y_pos.i.hi >> 2;
    arg0->y_pos.i.hi = tmp + (s16)arg0->unk42;
    tmp = D_8009A1F8[0].x_pos.i.hi >> 2;
    pos = tmp + (s16)arg0->unk40;
    diff = pos - ref;
    arg0->x_pos.i.hi = pos;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos - 0x140;
            } else {
                arg0->x_pos.i.hi = ref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->x_pos.i.hi = pos + 0x140;
            } else {
                arg0->x_pos.i.hi = ref - 0x10;
            }
        }
    }
    cur = arg0->y_pos.i.hi;
    yref = arg0->unk18.i.hi;
    diff = cur - yref;
    if (diff >= 0) {
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur - 0x140;
            } else {
                arg0->y_pos.i.hi = yref + 0x10;
            }
        }
    } else {
        diff = -diff;
        if (diff >= 0x10) {
            if (diff >= 0x148) {
                arg0->y_pos.i.hi = cur + 0x140;
            } else {
                arg0->y_pos.i.hi = yref - 0x10;
            }
        }
    }
}
