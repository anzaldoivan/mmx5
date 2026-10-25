#include "types.h"

extern s32 func_80013674(void);
extern u8 D_800D1598;

void func_80020CF4(u8* a0) {
    func_80013674();
    a0[0x1D] = 0;
    a0[0x1E] = 0;
    D_800D1598 = 0;
    if (((s8*)a0)[0xD] == 0) {
        *(s32*)(a0 + 0xB0) = 0;
        *(s32*)(a0 + 0xB4) = 0;
        *(s32*)(a0 + 0xB8) = 0;
        *(s16*)(a0 + 0xBC) = 0;
        *(s16*)(a0 + 0xBE) = 0;
        a0[0xCC] = a0[0xA1];
    }
    a0[0] = 9;
}
