#include "types.h"

extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern u8* func_8003D3A8(s32, s32, s32, u8*);

void func_80044778(u8* arg0) {
    u8* r;

    if (*(s8*)(arg0 + 0x45) & 0x80) {
        func_8003B33C(arg0, 0x83);
        func_80016490(1, 5, arg0);
        arg0[0x8C] = 1;
        arg0[6]++;
        r = func_8003D3A8(1, 0x22, 0, arg0);
        if (r == 0) {
            r[0x14] = arg0[0x14];
            r[0x15] = arg0[0x15];
        }
    }
}
