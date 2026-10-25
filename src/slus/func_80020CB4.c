#include "types.h"

extern s32 func_80013674(void);

void func_80020CB4(u8* arg0) {
    arg0[0] = 4;
    arg0[0xC] = 0xD;
    arg0[0xD] = 0;
    arg0[0x1D] = 0;
    func_80013674();
}
