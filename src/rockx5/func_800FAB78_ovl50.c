#include "types.h"

extern u8 D_80091C44;
extern s32 func_80016490(s32, s32, void*);

void func_800FAB78_ovl50(u8* arg0) {
    if (D_80091C44 == 0) {
        func_80016490(2, 0x6C, 0);
        func_80016490(2, 0x4E, 0);
        arg0[1]++;
    }
}
