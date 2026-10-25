#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8003CE30(u8*);

void func_8003AFEC(u8* p) {
    func_8003B33C(p, 0x1C);
    *(s32*)(p + 0x68) = 0;
    *(s16*)(p + 0xC) = 0;
    *(u16*)(p + 0xE) &= 0xFFF0;
    func_8003CE30(p);
    p[0x5] = 0xE;
    p[0x6] = 1;
}
