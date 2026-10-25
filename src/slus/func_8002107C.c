#include "types.h"

extern s32 func_80013674(void);

void func_8002107C(u8* a0) {
    a0[0x0] = 0x11;
    a0[0xC] = 0xF;
    a0[0xD] = 1;
    a0[0x1] = 0;
    a0[0x1D] = 0;
    func_80013674();
}
