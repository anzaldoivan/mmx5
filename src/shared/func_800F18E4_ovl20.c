#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800F18E4_ovl20(u8* arg0) {
    if (D_80091C44 == 0) {
        D_800D1C28[0] = 0;
        arg0[2]++;
    }
}
