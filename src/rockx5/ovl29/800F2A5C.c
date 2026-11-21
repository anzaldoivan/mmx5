#include "types.h"
#include "mmx5/globals.h"

#define func_800F08BC_ovl11 func_800F2A5C_ovl29
#include "shared/func_800F08BC_ovl11.c"
#undef func_800F08BC_ovl11

extern int func_8002D7A0();

void func_800F2AE8_ovl29(signed char* arg0) {
    if (arg0[4] == 3) {
        func_8002D760(arg0);
    } else {
        func_8002D7A0(arg0);
    }
}
