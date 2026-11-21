#include "types.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DC04.c, AGPL-3.0 (THIRD_PARTY.md). */

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(u8, u8); /* extern */
void func_80017D88();       /* extern */
void func_80027288();       /* extern */
void func_8002D004();       /* extern */
extern s8 D_8009A424;

void func_8001EF88(void* arg0) {
    if (D_8009A424 == 0) {
        func_80027288();
        func_80017D88();
        silence_sound(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
#undef M2C_FIELD

extern void func_800132F8(s8 arg);
extern u16 D_800C9320;

void func_8001EFF0(u8* p) {
    s16 t;
    s32 flag;

    t = --*(s16*)(p + 4);
    flag = 0;
    if (t < 301) {
        flag = (D_800C9320 & 0x8F0) != 0;
    }
    if (t <= 0) {
        flag = 1;
    }
    if (flag) {
        p[1]++;
        func_800132F8(8);
    }
}

void func_8001F06C(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 3) {
        arg0[1]++;
    }
}
