#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F6E38_ovl04(u8* obj) {
    if (obj[0x8F] != 0) {
        obj[0x8F]--;
        animate_object(obj);
    } else {
        clear_object_slot(obj);
    }
}
