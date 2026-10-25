#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8003CE30(u8*);

void func_8003ABD0(u8* p) {
    func_8003B33C(p, 0x12);
    *(s32*)(p + 0x28) = *(s32*)(p + 0x11C);
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s8*)(p + 0x84) = -1;
    if (*(s32*)(p + 0xFC) & 0x10) {
        p[0x85] = 0xA;
    } else {
        p[0x85] = 0x12;
    }
    p[0x86] = 3;
    func_8003CE30(p);
    p[0x5] = 0xD;
    p[0x6] = 0;
}
