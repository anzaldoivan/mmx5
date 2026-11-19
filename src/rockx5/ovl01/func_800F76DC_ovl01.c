#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

void func_800F76DC_ovl01(u8* a0) {
    s32 r;

    move_object(a0);
    r = is_off_screen(a0, 0x300, 0x20);
    if (r == 1) {
        a0[5] = r;
        a0[6] = 0;
    }
}
