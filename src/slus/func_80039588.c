#include "types.h"

extern u8 D_800D1D10;
extern void func_8003B2E4(void);

s32 func_80039588(u8* a0) {
    if (*(s8*)(a0 + 0xD3) != 0) {
        return 0;
    }
    if (!(D_800D1D10 & 8)) {
        return 0;
    }
    if (!(*(u16*)(a0 + 0x7C) & 8)) {
        return 0;
    }
    func_8003B2E4();
    return 1;
}
