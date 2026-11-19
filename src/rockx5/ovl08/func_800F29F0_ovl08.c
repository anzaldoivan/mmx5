#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

void func_800F29F0_ovl08(u8* a0) {
    if (is_off_screen(a0, 0xA0, 0x50) == 0) {
        func_8002D9EC(a0, 0x70, 0x40);
    } else {
        a0[4] = 7;
    }
}
