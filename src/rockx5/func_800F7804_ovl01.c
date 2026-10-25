#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800F7804_ovl01(u8* a0) {
    func_8002DF54(a0);
    if (func_8002D938(a0, 0x300, -0x10) == 0) {
        a0[6]++;
    }
}
