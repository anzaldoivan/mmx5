#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8003CE10(u8*);
extern void func_8003CE30(u8*);

void func_8003B040(u8* p) {
    func_8003B33C(p, 0x1D);
    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x68) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    p[0x67] = 1;
    func_8003CE10(p);
    func_8003CE30(p);
    p[0x5] = 0xE;
    p[0x6] = 2;
}
