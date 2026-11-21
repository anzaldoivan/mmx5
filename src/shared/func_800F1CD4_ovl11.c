/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004AD78.c via src/slus/func_80050C60.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800F1CD4_ovl11(u8* arg0) {
    u8 temp_v1;

    move_object(arg0);
    animate_object(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x54] = 0;
        clear_object_slot(arg0);
        return;
    }
    temp_v1 = arg0[0x54];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_8009A420_as_s32 & 1) == *(s8*)(arg0 + 7)) {
            func_8002D89C(arg0);
        }
    } else {
        func_8002D89C(arg0);
    }
}
