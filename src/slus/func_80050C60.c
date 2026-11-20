/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004AD78.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)
#define M2C_UNK s32

#define clear_object_slot ((M2C_UNK(*)(u8*))clear_object_slot)
#define func_8002D89C func_8002D89C

void func_80050C60() {
    // !FAKE: pins a0 to $4; gcc 2.7.2 allocates another register without it (byte mismatch)
    register u8* a0 asm("$4");
    u8* arg0 = a0;
    u8 temp_v1;

    move_object(arg0);
    ((void (*)(u8*))animate_object)(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x5C] = 0;
        clear_object_slot(arg0);
        return;
    }
    temp_v1 = arg0[0x5C];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_8009A420_as_s32 & 1) == *(s8*)(arg0 + 7)) {
            func_8002D89C(arg0);
        }
    } else {
        func_8002D89C(arg0);
    }
}

#undef clear_object_slot
#undef func_8002D89C
