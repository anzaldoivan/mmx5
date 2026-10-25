/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049F98.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

s32 func_8002DF78(void);
s32 func_8002DFB0(void);
void func_8004FF94(s32, s32, s32, s32);
extern u8 D_800E9588[];

void func_8004FE6C(X4_Obj* self, s8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    s16 x;
    s16 y;
    s32 r;
    s32 a3;
    s32 t;

    arg2 &= func_8002DF78();
    if (func_8002DF78() & 1) {
        x = self->x_pos.u.hi + arg2;
    } else {
        x = self->x_pos.u.hi - arg2;
    }
    arg3 &= func_8002DF78();
    if (func_8002DF78() & 1) {
        y = self->y_pos.u.hi + arg3;
    } else {
        y = self->y_pos.u.hi - arg3;
    }
    r = func_8002DFB0();
    if (arg4 == 0 || r % arg4 == 0) {
        u8* p = &D_800E9588[1];
        t = *p + 1;
        *p = t;
        a3 = 3;
        if (t & 1) {
            a3 = 2;
        }
    } else {
        a3 = 0xFF;
    }
    func_8004FF94(arg1, x, y, a3);
}
