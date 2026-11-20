#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_800F6C48_ovl01(u8* a0);

void func_800F67B0_ovl01(u8* a0) {
    move_object(a0);
    animate_object(a0);
    if (--D_1F80004C.bytes[0x85] == 0xFF) {
        if (--D_1F80004C.bytes[0x84] == 0xFF) {
            a0[5] = 3;
            func_800F6C48_ovl01(a0);
        }
        a0[6] = 0;
    }
}
