#include "types.h"

extern void func_8002C1C8(void);
extern u8* func_8002D27C(void);

void func_800EF114_ovl21(u8* a0) {
    u8* p;

    func_8002C1C8();
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x30;
        p[2] = 4;
        *(u8**)(p + 0x50) = a0;
    }
    a0[1]++;
}
