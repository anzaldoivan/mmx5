#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern s8 D_8009A0A5;
extern s16 D_8009A202;

void func_800EFE78_ovl04(u8* a0) {
    if (D_8009A0A5 == 20 && D_8009A202 == 0xC80) {
        func_80016490(5, 10, 0);
        a0[6]++;
    }
}
