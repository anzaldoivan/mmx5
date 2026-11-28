#include "types.h"

extern u8* func_8002B4E4(s32);

void func_8002B61C(u8* p) {
    u8* q;

    while (p[3] != 0xF) {
        q = func_8002B4E4(p[3]);
        if (q != 0) {
            q[0] = 1;
            q[1] = p[1];
            q[2] = p[2];
            *(u16*)(q + 0xA) = *(u16*)(p + 4);
            *(u16*)(q + 0xE) = *(u16*)(p + 6);
            *(u8**)(q + 0x10) = p;
        }
        p += 8;
    }
}
