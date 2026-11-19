#include "types.h"
#include "mmx5/globals.h"

extern void func_80017768(void);

void func_800F1190_ovl07(u8* a0) {
    ((s32(*)())func_8003D2C4)();
    a0[4] = 3;
    a0[5] = 0;
    func_80017768();
}
