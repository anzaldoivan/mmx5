#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_800D1C78[];

void func_800F2A28_ovl20(u8* a0) {
    if (D_800D1C78[1] >= 5) {
        clear_object_slot();
    } else {
        func_8002D9EC(a0, 0x40, 0x40);
    }
}
