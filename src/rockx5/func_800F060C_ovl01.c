#include "types.h"

extern void (*D_800FC6A4_ovl01[])(u8*);
void func_800F074C_ovl01(u8*);

void func_800F060C_ovl01(u8* arg0) {
    D_800FC6A4_ovl01[(signed char)arg0[6]](arg0);
    func_800F074C_ovl01(arg0);
}
