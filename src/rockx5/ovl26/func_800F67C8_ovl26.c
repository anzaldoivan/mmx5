#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

void func_800F67C8_ovl26(u8* p) {
    s32 a;
    s32 b;

    animate_object(p);
    func_8002D89C(p);
    b = ((s8*)p)[2];
    if (b == 0) {
        b = ((s8*)p)[0x45];
        a = 1;
    } else {
        *(u16*)(p + 0x42) = *(u16*)(*(u8**)(p + 0x50) + 0x42);
        apply_object_motion(p);
        a = is_off_screen(p, 0x20, 0x20);
        b = 1;
    }
    if (a == b) {
        p[4] = 2;
    }
}
