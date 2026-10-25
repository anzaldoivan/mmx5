#include "types.h"
#include "addr.h"

extern u8* func_8002D144(void);
extern u8 D_8009A1F8[];

void func_800F9E98_ovl27(u8* a0) {
    u8* base = D_8009A1F8;
    u8* p;

    base[0x48] = 1;
    base[0x47] = 1;
    *(s16*)(base + 0x24) = 0x12A0;
    *(s16*)(base + 0x26) = 0x12A0;
    *(s16*)(base + 0x28) = 0;
    *(s16*)(base + 0x2A) = 0;
    p = func_8002D144();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x18;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
        a0[6]++;
    }
}
