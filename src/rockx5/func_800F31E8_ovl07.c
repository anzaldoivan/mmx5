#include "types.h"

extern u8 D_800D1CA0[];
extern void (*D_801010D8_ovl07[])(signed char*);

void func_800F31E8_ovl07(signed char* arg0) {
    if (D_800D1CA0[1] & 1) {
        arg0[4] = 2;
    }
    D_801010D8_ovl07[arg0[4]](arg0);
}
