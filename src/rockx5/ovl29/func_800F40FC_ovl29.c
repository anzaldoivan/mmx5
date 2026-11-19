#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

void func_800F40FC_ovl29(u8* obj) {
    u8* child;

    if (**(s8**)(obj + 0x80) == 0) {
        obj[6]++;
        set_animation(obj, 0xF);
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 2;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 3;
            *(u8**)(child + 0x50) = obj;
        }
        child = func_8002D27C();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x26;
            child[2] = 0;
            *(u8**)(child + 0x50) = obj;
        }
        obj[0x67] = 1;
        *(s32*)(obj + 0x2C) = 0xD00;
        *(s16*)(obj + 0x7C) = 0;
    }
}
