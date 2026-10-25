#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_800F0FFC_ovl05(u8* a0);
extern s32 func_8004FC64(u8* a0);

void func_800F0EFC_ovl05(u8* a0) {
    func_8002DF54(a0);
    if (func_800F0FFC_ovl05(a0) != 0) {
        a0[3] = 0;
        func_8004FC64(a0);
        a0[4] = 2;
    }
}
