#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"

void func_800F4658_ovl26(u8* obj) {
    u8 state;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        if (*(s8*)(obj + 0x5C) >= D_800D1CA2 / 2 ||
            (u32)(random_byte() & 0xF) < 8) {
            state = 8;
        } else {
            state = 9;
        }
        obj[5] = state;
        obj[6] = 0;
    }
}
