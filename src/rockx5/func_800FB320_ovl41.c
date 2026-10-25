#include "types.h"

extern void SetDispMask(s32);
extern u8 D_800D1F3C;

void func_800FB320_ovl41(u8* arg0) {
    if (D_800D1F3C == 2) {
        arg0[1]++;
        SetDispMask(1);
    }
}
