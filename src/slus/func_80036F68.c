#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8003B0EC(u8* obj);

void func_80036F68(u8* obj) {
    animate_object(obj);
    move_object(obj);
    if (*(s8*)(obj + 0x46) < 0) {
        func_8003B33C(obj, 0x1F);
        func_8003B0EC(obj);
    }
}
