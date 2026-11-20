#include "types.h"
#include "mmx5/object.h"

void func_800F7570_ovl26(u8* a0) {
    move_object(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        a0[6]++;
    }
}
