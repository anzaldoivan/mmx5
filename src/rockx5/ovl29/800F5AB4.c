#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;

void func_800F5AB4_ovl29(u8* a0) {
    if (D_8009A197 == 0) {
        animate_object();
        move_object(a0);
    }
    if (func_800317B8(a0) != 0) {
        a0[4] = 2;
        return;
    }
    if (func_80031DD0(a0) < 0 || a0[0x70] != 0) {
        goto block;
    }
    ((s32(*)())func_8002F8FC)(a0);
    if (a0[0x70] != 0) {
    block:
        ((s32(*)())func_8004FD24)(a0);
        a0[4] = 2;
        return;
    }
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
        return;
    }
    a0[4] = 2;
}

#define D_800EEBA0_ovl00 func_800F5B7C_ovl29
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
