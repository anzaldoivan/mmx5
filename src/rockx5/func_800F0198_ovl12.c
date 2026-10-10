#include "types.h"

extern void (*D_800F2058_ovl12[])(u8*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F0198_ovl12(u8* arg0) {
    D_800F2058_ovl12[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x40, 0x40);
}
