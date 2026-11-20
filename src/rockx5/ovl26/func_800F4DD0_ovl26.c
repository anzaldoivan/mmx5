#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800F4DD0_ovl26(u8* a0) {
    u8* s;

    animate_object(a0);
    s = D_1F80004C.bytes;
    if (s[0x97] == 1) {
        s[0x97] = 0;
        set_animation(a0, 6);
        a0[6]++;
    }
}
