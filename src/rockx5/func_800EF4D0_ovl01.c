#include "types.h"

extern void func_8002D720(u8* arg0);
extern u8 D_8009A1F8[];

void func_800EF4D0_ovl01(u8* arg0) {
    u8* p = D_8009A1F8;

    p[0x57] = 0;
    p[0xAB] = 0;
    p[0x98] = 0;
    p[0xEC] = 0;
    func_8002D720(arg0);
}
