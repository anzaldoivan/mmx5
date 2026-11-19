#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F7138_ovl28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        move_object(obj);
    }
}
