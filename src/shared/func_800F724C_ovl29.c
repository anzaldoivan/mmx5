#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FA514_ovl29[])(u8*);

void func_800F724C_ovl29(u8* arg0) {
    D_800FA514_ovl29[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x30, 0x30);
}
