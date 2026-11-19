#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"

void func_800F7804_ovl01(u8* a0) {
    move_object(a0);
    if (is_off_screen(a0, 0x300, -0x10) == 0) {
        a0[6]++;
    }
}
