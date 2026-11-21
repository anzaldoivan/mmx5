#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F0280_ovl01(u8* obj) {
    animate_object();
    *(s32*)(obj + 0x24) = 0x60000;
    move_object(obj);
}

void func_800F02B4_ovl01(u8* arg0) {
    if ((D_8009A0AA - *(s16*)(arg0 + 0xA)) >= 0xB5) {
        arg0[0x7A] = 0;
        arg0[0x5] = 2;
    }
}
