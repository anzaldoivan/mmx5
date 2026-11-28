/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029818.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027FA8, AGPL-3.0; proven shared with X6 by exact signature 8a39aba72637 (see THIRD_PARTY.md). */
#include "types.h"

void func_8002A9A0(X4_BackgroundObj* arg0) {
    s16 delta;

    delta = arg0->x_pos.i.hi - arg0->unk14.i.hi;
    if (delta >= 0) {
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->x_pos.i.hi = arg0->x_pos.i.hi - 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi + 0x10;
            }
        }
    } else {
        delta = -delta;
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->x_pos.i.hi = arg0->x_pos.i.hi + 0x140;
            } else {
                arg0->x_pos.i.hi = arg0->unk14.i.hi - 0x10;
            }
        }
    }

    delta = arg0->y_pos.i.hi - arg0->unk18.i.hi;
    if (delta >= 0) {
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->y_pos.i.hi = arg0->y_pos.i.hi - 0x140;
            } else {
                arg0->y_pos.i.hi = arg0->unk18.i.hi + 0x10;
            }
        }
    } else {
        delta = -delta;
        if (delta >= 0x10) {
            if (delta >= 0x148) {
                arg0->y_pos.i.hi = arg0->y_pos.i.hi + 0x140;
            } else {
                arg0->y_pos.i.hi = arg0->unk18.i.hi - 0x10;
            }
        }
    }
}
