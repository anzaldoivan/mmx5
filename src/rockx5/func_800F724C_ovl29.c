#include "types.h"

extern void (*D_800FA514_ovl29[])(u8*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F724C_ovl29(u8* arg0) {
    D_800FA514_ovl29[(signed char)arg0[6]](arg0);
    func_8002D9EC(arg0, 0x30, 0x30);
}
