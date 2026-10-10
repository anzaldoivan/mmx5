#include "types.h"

extern void (*D_8007B56C[])(u8*);
void func_8002D89C(u8*);

void func_8004E210(u8* arg0) {
    D_8007B56C[(signed char)arg0[5]](arg0);
    func_8002D89C(arg0);
}
