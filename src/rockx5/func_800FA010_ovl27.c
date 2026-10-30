#include "types.h"

extern void func_80044DD0(s32 a0);
extern u8 D_800D1C24;

void func_800FA010_ovl27(u8* o) {
    D_800D1C24 = 1;
    func_80044DD0(0);
    o[6]++;
}
