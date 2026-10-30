#include "types.h"

extern s32 func_8003D2C4(void);
extern void func_80017768(void);

void func_800F1190_ovl07(u8* a0) {
    func_8003D2C4();
    a0[4] = 3;
    a0[5] = 0;
    func_80017768();
}
