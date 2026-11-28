#include "types.h"
#include "mmx5/globals.h"

extern void (*D_801010D8_ovl07[])(signed char*);

void func_800F31E8_ovl07(signed char* arg0) {
    if (D_800D1CA0.u[1] & 1) {
        arg0[4] = 2;
    }
    D_801010D8_ovl07[arg0[4]](arg0);
}
