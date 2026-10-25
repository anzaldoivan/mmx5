#include "types.h"

extern s32 func_800439A8(u8* obj);
extern void func_8003D200(u8* obj);
extern s32 func_80016490(s32, s32, void*);

void func_80036D2C(u8* obj) {
    if (func_800439A8(obj) != 0) {
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s8*)(obj + 0x67) = -1;
        obj[0x84] = 0;
        *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
    } else {
        if (obj[0x45] & 0x40) {
            obj[0x45] &= 0x3F;
            func_8003D200(obj);
        }
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] &= 0x3F;
            func_80016490(1, 5, obj);
            obj[0x8C] = 1;
            obj[6]++;
        }
    }
}
