#include "types.h"
#include "mmx5/globals.h"

extern void SetDispMask(s32);

void func_800FA664_ovl52(u8* arg0) {
    SetDispMask(1);
    func_8002385C(0x45, 0xFF, 0);
    arg0[1]++;
}
