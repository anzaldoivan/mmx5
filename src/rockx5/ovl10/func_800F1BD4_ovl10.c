#include "types.h"

extern u8* func_8002C938();
extern s32 D_800FB638_ovl10;

void func_800F1BD4_ovl10(u8* arg0, u8 arg1) {
    u8* obj = func_8002C938();

    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x12;
        obj[2] = arg1;
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42);
        *(s32**)(obj + 0x30) = &D_800FB638_ovl10;
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        *(s32*)(obj + 0x8) = *(s32*)(arg0 + 0x8);
        *(s32*)(obj + 0xC) = *(s32*)(arg0 + 0xC);
    }
}
