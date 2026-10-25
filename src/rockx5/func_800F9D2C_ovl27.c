#include "types.h"
#include "addr.h"

extern u8* func_8002D144(void);
extern u8 D_8009A1F8[];

void func_800F9D2C_ovl27(u8* a0) {
    u8* p;
    u8* base;

    p = func_8002D144();
    if (p != 0) {
        base = D_8009A1F8;
        p[0] = 1;
        p[1] = 0x1A;
        *(s16*)(p + 0xA) = *(s16*)(base + 0xA) + 0xA0;
        *(s16*)(p + 0xE) = *(s16*)(base + 0xE) + 0x78;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
    }
    a0[5]++;
}
