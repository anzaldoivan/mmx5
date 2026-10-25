#include "types.h"

extern void (*D_8007B5B4[])(u8*);
void func_8002D89C(u8*);

void func_8004EF88(u8* arg0) {
    D_8007B5B4[(signed char)arg0[5]](arg0);
    if ((signed char)arg0[4] == 1) {
        func_8002D89C(arg0);
    }
}
