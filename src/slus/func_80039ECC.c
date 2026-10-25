#include "types.h"

extern void func_8003B1A8(u8* a0);
extern void func_8003A418(u8* a0);
extern s8 D_800D1C0F;

s32 func_80039ECC(u8* a0) {
    if (D_800D1C0F != 0) {
        func_8003B1A8(a0);
        return 1;
    }
    if (*(s8*)(a0 + 0xD0) > 0) {
        func_8003A418(a0);
        return 1;
    }
    return 0;
}
