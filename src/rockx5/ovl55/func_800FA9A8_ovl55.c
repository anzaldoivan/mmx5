#include "types.h"

extern void func_80013288(s32);
extern u8 D_8009A1F8[];

void func_800FA9A8_ovl55(u8* e) {
    u8* p = D_8009A1F8;

    p[0x3] = 0;
    p[0x57] = 1;
    *(s16*)(p + 0x5E) = 0;
    *(s16*)(p + 0x62) = 0;
    p[0xA0] = 1;
    p[0xAB] = 1;
    *(s16*)(p + 0xB2) = 0;
    *(s16*)(p + 0xB6) = 0;
    p[0xF4] = 1;
    func_80013288(8);
    e[1]++;
}
