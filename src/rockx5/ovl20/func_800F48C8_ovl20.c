#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s8 D_800D1C30;

void func_800F48C8_ovl20(u8* a0) {
    if (D_800D1C30 != 0) {
        clear_object_slot();
    } else {
        func_8002D9EC(a0, 0x80, 0x40);
    }
}
