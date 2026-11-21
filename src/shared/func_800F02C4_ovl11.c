#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8002D800(u8* a0);

void func_800F02C4_ovl11(u8* obj) {
    animate_object(obj);
    if (obj[0x47] >= 12) {
        move_object(obj);
    }
    if (func_8002D800(obj) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        clear_object_slot(obj);
    }
}
