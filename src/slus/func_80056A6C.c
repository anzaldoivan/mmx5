#include "types.h"

extern int func_8002D6FC();
extern s32 D_80091D54;
extern s16 D_8009A41A;

void func_80056A6C(u8* obj) {
    D_80091D54 = 1;
    D_8009A41A = 0x3C;
    func_8002D6FC(obj);
}
