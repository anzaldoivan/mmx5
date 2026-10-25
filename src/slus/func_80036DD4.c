#include "types.h"

extern s32 func_800439A8(u8* obj);
extern s32 func_800398E8(u8* obj);
extern void func_8003AC44(u8* obj);
extern void func_8003D200(u8* obj);

void func_80036DD4(u8* obj) {
    if (func_800439A8(obj) != 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[0x84] = 0;
        *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
    } else if (func_800398E8(obj) != 0) {
        func_8003AC44(obj);
    } else if (obj[0x45] & 0x40) {
        obj[0x45] &= 0x3F;
        func_8003D200(obj);
    }
}
