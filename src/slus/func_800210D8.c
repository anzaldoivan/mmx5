#include "types.h"

extern s32 func_80013674(void);
extern u8 D_8009A428;

void func_800210D8(u8* arg0) {
    D_8009A428 = 0;
    arg0[0] = 0x14;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    arg0[0xC] = 0xB;
    arg0[0xD] = 0;
    func_80013674();
}
