#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F7544_ovl29(u8* a0) {
    func_800317B8(a0);
    move_object(a0);
    animate_object(a0);
    ((s32(*)())func_8002D9EC)(a0, 0x30, 0x80);
    if (*(s8*)(a0 + 3) == 0) {
        a0[4]++;
        a0[5] = 0;
        a0[6] = 0;
    }
}
