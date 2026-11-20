#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

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
