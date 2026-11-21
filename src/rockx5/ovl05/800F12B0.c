#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F12B0_ovl05(u8* a0) {
    u8 v;

    a0[3] = 0;
    v = (*(u8**)(D_1F80004C.bytes + 0x80))[0x91];
    switch (v) {
    case 0:
        a0[4] = 2;
        break;
    case 2:
        func_8002D9EC(a0, 0x40, 0x40);
        break;
    }
}

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F1314_ovl05
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
