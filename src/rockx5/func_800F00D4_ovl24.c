#include "types.h"

extern void func_80013288(s32);
extern u8 D_800D1F3C;

void func_800F00D4_ovl24(u8* arg0) {
    if (D_800D1F3C == 2) {
        func_80013288(8);
        arg0[2]++;
    }
}
