#include "types.h"
#include "mmx5/object.h"

void func_800F761C_ovl01(u8* a0) {
    s8 s = ((s8*)a0)[7];

    if (s == 0) {
        *(s32*)(a0 + 0x20) = 0xFFFC0000;
        a0[7]++;
        move_object(a0);
    } else if (s == 1) {
        move_object(a0);
    }
}
