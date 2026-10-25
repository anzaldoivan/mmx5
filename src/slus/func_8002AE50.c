/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80029D18.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];
void func_8002B070(s16, s16, s16, s16, u8);

void func_8002AE50(void) {
    X4_BackgroundObj* bg = D_8009A1F8;

    if (bg->unk14.i.hi != bg->x_pos.i.hi) {
        if (bg->unk14.i.hi < bg->x_pos.i.hi) {
            func_8002B070(bg->x_pos.i.hi + 0x150, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 1);
        } else {
            func_8002B070(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi - 0x10,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 2);
        }
    }
    if (bg->unk18.i.hi != bg->y_pos.i.hi) {
        if (bg->unk18.i.hi < bg->y_pos.i.hi) {
            func_8002B070(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi + 0x100, bg->y_pos.i.hi + 0x120, 3);
        } else {
            func_8002B070(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi - 0x10, 4);
        }
    }
}
