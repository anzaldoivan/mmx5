#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FA820_ovl50(u8* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.u[3] = 1;
        arg0[1]++;
    }
}
