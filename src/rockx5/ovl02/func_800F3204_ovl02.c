#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800F48B4_ovl02[])(u8*);

void func_800F3204_ovl02(u8* arg0) {
    D_800F48B4_ovl02[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x20, 0x20);
}
