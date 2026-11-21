#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A1F8[];

void func_800EF0B8_ovl21(u8* a0) {
    u8* p;

    *(s16*)(a0 + 4) += 1;
    if (*(s16*)(a0 + 4) >= 9) {
        p = D_8009A1F8;
        *(s32*)(p + 0x8) = 0x4000000;
        *(s32*)(p + 0xC) = 0;
        p[0x4C] = 1;
        p[3] = 1;
        *(s16*)(a0 + 4) = 0;
        a0[1]++;
    }
}

extern void func_8002C1C8(void);

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

void func_800EF170_ovl21(u8* arg0) {
    *(s16*)(arg0 + 4) += 1;
    if (*(s16*)(arg0 + 4) >= 0x78) {
        arg0[1]++;
    }
}

#define func_80013288 func_800132F8

#define func_800EEC94_ovl21 func_800EF1AC_ovl21
#include "shared/func_800EEC94_ovl21.c"
#undef func_800EEC94_ovl21
