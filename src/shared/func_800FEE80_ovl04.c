#include "types.h"
#include "mmx5/object.h"

extern u8 D_800D1C00[];

void func_800FEE80_ovl04(void) {
    D_800D1C00[0x26] |= 4;
    clear_object_slot();
}
