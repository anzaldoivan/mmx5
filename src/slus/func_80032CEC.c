/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800328B0.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern X4_BackgroundObj D_8009A1F8[3];
/* !FAKE: pinned offsets; X4_BackgroundObj (types.h) lacks s8 unk3 @0x03, s16 unk1E..unk32 @0x1E-0x32, s8 unk37 @0x37 */
#define BG_S8(o, off) (*(s8*)((u8*)(o) + (off)))
#define BG_S16(o, off) (*(s16*)((u8*)(o) + (off)))

void func_80032CEC() {
    // !FAKE: pins a0 to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register X4_BackgroundObj* a0 asm("$4");
    // !FAKE: pins o to $8; gcc 2.7.2 allocates another register without it (byte mismatch)
    register X4_BackgroundObj* o asm("$8") = a0;
    s16 dx;
    s16 dy;

    BG_S8(o, 0x03) = 0;
    if (BG_S8(o, 0x37) < 0) {
        dx = o->unk14.i.hi + o->x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi;
    } else {
        dx = o->unk14.i.hi + o->x_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].x_pos.i.hi;
        dy = o->unk18.i.hi + o->y_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        BG_S8(o, 0x03) = 1;
        return;
    }
    if (BG_S8(o, 0x37) < 0) {
        dx = BG_S16(o, 0x1E) + o->x_pos.i.hi;
        dy = BG_S16(o, 0x22) + o->y_pos.i.hi;
    } else {
        dx = BG_S16(o, 0x1E) + o->x_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].x_pos.i.hi;
        dy = BG_S16(o, 0x22) + o->y_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        BG_S8(o, 0x03) = 1;
        return;
    }
    if (BG_S8(o, 0x37) < 0) {
        dx = BG_S16(o, 0x26) + o->x_pos.i.hi;
        dy = BG_S16(o, 0x2A) + o->y_pos.i.hi;
    } else {
        dx = BG_S16(o, 0x26) + o->x_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].x_pos.i.hi;
        dy = BG_S16(o, 0x2A) + o->y_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        BG_S8(o, 0x03) = 1;
        return;
    }
    if (BG_S8(o, 0x37) < 0) {
        dx = BG_S16(o, 0x2E) + o->x_pos.i.hi;
        dy = BG_S16(o, 0x32) + o->y_pos.i.hi;
    } else {
        dx = BG_S16(o, 0x2E) + o->x_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].x_pos.i.hi;
        dy = BG_S16(o, 0x32) + o->y_pos.i.hi -
             D_8009A1F8[BG_S8(o, 0x37)].y_pos.i.hi;
    }
    if ((u16)dx < 320 && (u16)dy < 240) {
        BG_S8(o, 0x03) = 1;
        return;
    }
}
