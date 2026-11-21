#include "types.h"
#include "mmx5/globals.h"

extern s8 D_8009A23C;
extern s8 D_800D1C26;

void func_800EFD54_ovl04(u8* arg0) {
    if (D_800D1C26 & 1) {
        arg0[6]++;
        D_8009A23C = 0;
        func_8003D2C4();
    }
}
