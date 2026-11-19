#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F6BBC_ovl28(u8* obj) {
    animate_object(obj);
    func_800317B8(obj);
    func_8002D9EC(obj, 0x20, 0x14);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0x11);
        obj[5]++;
    }
    if (*(s8*)(*(u8**)(obj + 0x7C) + 4) == 2) {
        obj[4] = 2;
    }
}
