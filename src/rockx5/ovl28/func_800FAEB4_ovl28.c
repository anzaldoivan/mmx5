#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800FAEB4_ovl28(u8* obj) {
    if (++*(s32*)(obj + 0x8C) == 0x12) {
        obj[4] = 2;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    animate_object(obj);
    move_object(obj);
}
