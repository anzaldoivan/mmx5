#include "types.h"
#include "mmx5/globals.h"

void func_800F2948_ovl20(u8* obj) {
    if (((s8*)obj)[2] == 3) {
        animate_object(obj);
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_8002D89C(obj);
    }
}
