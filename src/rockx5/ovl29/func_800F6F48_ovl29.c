#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F6F48_ovl29(u8* a0) {
    ((void (*)())func_800317B8)(a0);
    if (--*(s16*)(a0 + 0x88) == 0) {
        *(s32*)(a0 + 0x24) = -*(s32*)(a0 + 0x24);
        *(s16*)(a0 + 0x88) = 7;
    }
    if (is_off_screen(a0, 0x100, 0x100) == 0) {
        func_8002D9EC(a0, 0x30, 0x30);
    } else {
        a0[5] = 0;
        a0[4]++;
    }
    move_object(a0);
    animate_object(a0);
}
