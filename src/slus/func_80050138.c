#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80050138(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x46) < 0) {
        clear_object_slot(obj);
        return;
    }
    if (*(s8*)(obj + 2) != 0) {
        move_object(obj);
    }
    func_8002D89C(obj);
}
