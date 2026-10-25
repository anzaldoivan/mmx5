#include "types.h"

extern void func_8003CE10(u8*);

void func_8003B148(u8* p) {
    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    *(s32*)(p + 0x24) = -*(s32*)(p + 0x12C);
    func_8003CE10(p);
    p[0x5] = 0x10;
    p[0x6] = 0;
}
