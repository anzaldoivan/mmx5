#include "types.h"
#include "mmx5/object.h"

void func_800F25AC_ovl10(u8* obj) {
    s32 v;
    s32 t;

    if (*(s32*)(obj + 0x84) & 1) {
        obj[3] ^= 1;
    }
    v = *(s32*)(obj + 0x84);
    t = v;
    v--;
    *(s32*)(obj + 0x84) = v;
    if (t == 0) {
        clear_object_slot();
    }
}
