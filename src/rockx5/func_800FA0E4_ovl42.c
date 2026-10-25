#include "types.h"

extern u8* func_8002D53C(void);
extern void func_80013288(s32);
extern u8 D_8009A1F8[];

void func_800FA0E4_ovl42(u8* arg0) {
    u8* p;

    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 0;
    p = func_8002D53C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xA;
        p[0x36] = 0x22;
        p[2] = 0;
    }
    func_80013288(8);
    arg0[1]++;
}
