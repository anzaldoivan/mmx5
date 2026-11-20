#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F2948_ovl11(u8* obj) {
    s32 st;

    animate_object(obj);
    move_object(obj);
    st = obj[0x15];
    if (st != 0) {
        if (obj[0x70] & 1) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
        }
    } else if (obj[0x70] & 2) {
        st = 0x40;
        obj[0x15] = st;
        *(s32*)(obj + 0x20) = -*(s32*)(obj + 0x20);
    }
}
