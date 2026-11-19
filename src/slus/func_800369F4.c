#include "types.h"
#include "mmx5/globals.h"

extern void (*D_80074718[])(u8*);

void func_800369F4(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) == 0) {
        animate_object(arg0);
        D_80074718[(s8)arg0[6]](arg0);
    }
}
