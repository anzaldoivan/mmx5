#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800F76DC_ovl01(u8* a0) {
    s32 r;

    func_8002DF54(a0);
    r = func_8002D938(a0, 0x300, 0x20);
    if (r == 1) {
        a0[5] = r;
        a0[6] = 0;
    }
}
