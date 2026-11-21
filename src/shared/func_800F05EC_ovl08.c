#include "types.h"
#include "mmx5/globals.h"

void func_800F05EC_ovl08(u8* obj) {
    if (D_8009A0AA - *(s16*)(obj + 0xA) >= 0xBD) {
        obj[0x7A] = 0;
        if (obj[0x80] == 0) {
            obj[0x5] = 2;
            obj[0x6] = 0;
            return;
        }
        *(s16*)(obj + 0x7C) = 1;
        obj[0x5] = 7;
        obj[0x6] = 0;
    }
}
