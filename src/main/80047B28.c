#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

void func_80047B28(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        apply_object_motion(obj);
    }
    func_8002D9EC(obj, 0x40, 0x40);
    if (*(s8*)(obj + 3) == 0) {
        obj[4]++;
    }
}

#define func_80046A6C func_80047B94
#include "shared/func_80046A6C.c"
#undef func_80046A6C
