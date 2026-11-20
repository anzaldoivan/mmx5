#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F9EF4_ovl28(u8* obj) {
    u8* child;

    if (*(s8*)(obj + 0x45) == 1) {
        *(s8*)(obj + 0x45) = 0;
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x24;
            child[2] = 0xB;
            *(u8**)(child + 0x7C) = obj;
        }
    }
    if (*(s8*)(obj + 0x45) == 2) {
        *(s8*)(obj + 0x45) = 0;
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x24;
            child[2] = 9;
            *(u8**)(child + 0x7C) = obj;
        }
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x24;
            child[2] = 0xA;
            *(u8**)(child + 0x7C) = obj;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 2);
        *(u16*)(obj + 0x7E) |= 1;
    }
    if (*(s16*)(obj + 0x7E) == 3) {
        obj[6]--;
    }
}
