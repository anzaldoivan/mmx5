#include "types.h"
#include "mmx5/object.h"

void func_800FD504_ovl39(u8* a0) {
    if (*(s8*)(a0 + 2) == 0) {
        *(s32*)(a0 + 0x20) = 0x18000;
    } else {
        *(s32*)(a0 + 0x20) = -0x18000;
    }
    *(s32*)(a0 + 0x24) = 0;
    move_object(a0);
    a0[6]++;
}
