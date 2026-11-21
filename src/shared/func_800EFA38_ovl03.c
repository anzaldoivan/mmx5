#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800EFA38_ovl03(u8* obj) {
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0x20000;
    move_object(obj);
    animate_object(obj);
}
