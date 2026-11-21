#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800F70DC_ovl09(u8* obj) {
    u8* p;

    func_800317B8(obj);
    if (--*(s32*)(obj + 0x8C) == 0) {
        obj[4] = 2;
    }
    p = *(u8**)(*(u8**)(obj + 0x7C) + 0x80);
    if (*(signed char*)(p + 5) == 11 || *(signed char*)(p + 4) == 2) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x10, 0x10);
    animate_object(obj);
    move_object(obj);
}
