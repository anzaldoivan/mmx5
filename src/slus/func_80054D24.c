#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];

void func_80054D24(u8* a0, u8* a1, u8* a2) {
    u8* p;

    if (*(s8*)(a2 + 0xD4) < 0) {
        a1[0x10] = 1;
        a1[0x12] = 1;
        func_80016490(0, 0x10, a0);
        p = D_8009A1F8;
        *(s32*)(a2 + 0x68) = 0;
        a0[5] = 2;
        *(s32*)(a0 + 0x80) = *(s8*)(p + 0x47);
        p[0x47] = 2;
    }
}
