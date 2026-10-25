#include "types.h"

extern s32 func_8002C50C(void);
extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F68[];
extern u8 D_8009A427;

void func_80021A90(u8* arg0) {
    func_8002C50C();
    D_8009A427 = 0;
    *(s16*)(arg0 + 8) = func_8001FF18(D_80070F68, 1);
    arg0[1] = 1;
}
