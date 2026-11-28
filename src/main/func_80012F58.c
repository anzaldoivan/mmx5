#include "types.h"

extern void ChangeTh(s32);
extern s32 D_8006FC2C;
extern s32 D_800D51E0;

void func_80012F58(s32 arg0) {
    D_8006FC2C = 1;
    D_800D51E0 = arg0;
    ChangeTh(0xFF000000);
}
