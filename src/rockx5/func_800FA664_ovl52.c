#include "types.h"

extern void SetDispMask(s32);
extern void func_8002385C(s32, s32, s32);

void func_800FA664_ovl52(u8* arg0) {
    SetDispMask(1);
    func_8002385C(0x45, 0xFF, 0);
    arg0[1]++;
}
