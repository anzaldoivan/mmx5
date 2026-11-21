#include "types.h"
#include "mmx5/globals.h"

extern int func_8002D7A0();

void func_800F5FE8_ovl06(signed char* arg0) {
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    if (arg0[4] == 3) {
        func_8002D7A0(arg0);
    } else {
        func_8002D760(arg0);
    }
}

#define D_800EEC60_ovl00 func_800F6034_ovl06
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F603C_ovl06
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
