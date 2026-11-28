#include "types.h"

extern s32 load_stage(void);

void func_80020CB4(u8* arg0) {
    arg0[0] = 4;
    arg0[0xC] = 0xD;
    arg0[0xD] = 0;
    arg0[0x1D] = 0;
    load_stage();
}

void func_80020CE8(u8* a0) {
    a0[0] = 3;
}
