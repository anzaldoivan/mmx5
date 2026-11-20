#include "types.h"
#include "mmx5/globals.h"

extern void func_800132F8(s8 arg);

void func_80034E0C(u8* arg0) {
    func_800132F8(8);
    ((s32(*)())func_800272DC)();
    arg0[5] = 1;
}
