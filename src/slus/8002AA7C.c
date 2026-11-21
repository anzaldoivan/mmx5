#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80071B0C[];
extern s8 D_800D1C00[];

void func_8002AA7C(u8* arg0) {
    u8* t = D_80071B0C;
    s8* p = D_800D1C00;
    s32 i = p[0xC] * 4 + p[0xD] * 2 + 1;
    arg0[4] = t[i];
}

#define animate_object func_8002AB84
#define move_object func_8002AB64

s32 func_8002AB64(s32); /* extern */
#define func_800EF574_ovl09 func_8002AAB4
#include "shared/func_800EF574_ovl09.c"
#undef func_800EF574_ovl09
#undef animate_object
#undef move_object

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002AAE0(X4_BackgroundObj* arg0) {
    X4_BackgroundObj* bg = D_8009A1F8;
    s32 x = (bg->x_pos.i.hi >> 1) + arg0->unk40;

    arg0->x_pos.i.hi = x;
    arg0->y_pos.i.hi = bg->y_pos.i.hi + arg0->unk42;
}

#define D_800EEC60_ovl00 func_8002AB18
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/80026028.c, AGPL-3.0 (THIRD_PARTY.md). */

extern X4_BackgroundObj D_8009A1F8[3];

void func_8002AB20(X4_BackgroundObj* arg0) {
    s32 t;
    u16 y;

    arg0->x_pos.u.hi = D_8009A1F8[0].x_pos.u.hi;
    y = D_8009A1F8[0].y_pos.u.hi;
    t = (s16)y / 2 + y;
    arg0->y_pos.u.hi = arg0->unk42 + t;
}
