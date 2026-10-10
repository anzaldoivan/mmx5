#include "types.h"

extern void (*D_800F48B4_ovl02[])(u8*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F3204_ovl02(u8* arg0) {
    D_800F48B4_ovl02[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x20, 0x20);
}
