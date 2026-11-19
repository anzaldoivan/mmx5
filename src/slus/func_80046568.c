#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80046568(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[1] == 0x2D) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        func_8002D9EC(obj, 0x40, 0x40);
    }
    if (((s8*)obj)[0x46] == 0) {
        clear_object_slot(obj);
    }
}
