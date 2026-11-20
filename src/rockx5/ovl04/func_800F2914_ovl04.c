#include "types.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800F2BCC_ovl04(u8* obj, s32 arg1);

void func_800F2914_ovl04(u8* obj) {
    func_800F2BCC_ovl04(obj, 0);
    set_animation(obj, 2);
    D_1F80004C.bytes[0x84] = 1;
    obj[0x62] = 3;
    obj[0x60] = 0;
    *(s16*)(obj + 0x7C) = 0xB4;
    obj[6]++;
}
