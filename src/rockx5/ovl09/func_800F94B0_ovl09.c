#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_800F94B0_ovl09(u8* obj) {
    if ((*(u8**)(obj + 0x50))[0x86] == 1) {
        clear_object_slot(obj);
    } else {
        (*(u16*)(obj + 0x54))++;
        if ((*(u16*)(obj + 0x54) & 7) == 0) {
            func_8004FD90(obj, 1, 3, 0x3F);
        }
    }
}
