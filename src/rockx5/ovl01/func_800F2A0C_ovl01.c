#include "types.h"

extern s32 func_800F30A0_ovl01(u8* arg0);
extern void func_800F2F44_ovl01(u8* arg0);
extern void (*D_800FC984_ovl01[])(u8*);

void func_800F2A0C_ovl01(u8* arg0) {
    if (func_800F30A0_ovl01(arg0) == 0) {
        D_800FC984_ovl01[(s8)arg0[6]](arg0);
        func_800F2F44_ovl01(arg0);
    }
}
