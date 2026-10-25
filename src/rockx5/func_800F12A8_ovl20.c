#include "types.h"

extern s8 D_800D1C28[];

void func_800F12A8_ovl20(u8* arg0) {
    if (D_800D1C28[1] == 0) {
        arg0[1] = 6;
        arg0[2] = 0;
    }
}
