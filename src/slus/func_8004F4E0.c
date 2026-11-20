#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_8004F4E0(u8* obj, u8* other) {
    s32 hit;

    animate_object(obj);
    hit = 0;
    if ((*(u32*)(other + 4) & 0xFFFF00) == 0xB00) {
        hit = 1;
    }
    if (*(s8*)(other + 5) == 0x34) {
        hit = 1;
    }
    if (hit) {
        func_8004F5CC(obj, other);
    } else {
        set_animation(obj, 4);
        obj[4]++;
    }
    func_8002D9EC(obj, 0x20, 0x20);
}
