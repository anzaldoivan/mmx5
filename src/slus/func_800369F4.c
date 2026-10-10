#include "types.h"

extern void func_80043B88(u8* arg0);
extern s32 func_80039ECC(u8* arg0);
extern void func_80017248(u8* obj);
extern void (*D_80074718[])(u8*);

void func_800369F4(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) == 0) {
        func_80017248(arg0);
        D_80074718[(s8)arg0[6]](arg0);
    }
}
