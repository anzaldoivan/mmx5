#include "types.h"
#include "addr.h"

extern void LoadImage(void*, void*);
extern u8 D_80071040;
extern u8 D_800C9310;

void func_8002002C(u8 arg0) {
    if (arg0 == 0) {
        LoadImage(&D_80071040, D_801F3000 + D_801F3004);
    } else {
        D_800C9310 |= 1;
    }
}
