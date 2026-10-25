#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_8003CE30(u8*);

void func_8003B0AC(u8* p) {
    func_8003B33C(p, 0x1E);
    func_8003CE30(p);
    p[0x5] = 0xE;
    p[0x6] = 3;
}
