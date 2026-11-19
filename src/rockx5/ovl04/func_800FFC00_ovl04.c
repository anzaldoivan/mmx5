#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8004FC64(u8* a0);

void func_800FFC00_ovl04(u8* a0) {
    animate_object(a0);
    move_object(a0);
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0) {
        func_8004FC64(a0);
        a0[4]++;
    } else if (is_off_screen(a0, 0x40, 0x40) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
    } else {
        a0[4]++;
    }
}
