#include "types.h"

extern s32 func_80044DE0();
extern void func_800171E8(u8*, s32);

void func_800FBC68_ovl38(u8* arg0) {
    if (func_80044DE0() == 0) {
        func_800171E8(arg0, 1);
        arg0[6]++;
    }
}
