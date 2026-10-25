#include "types.h"

void func_800EF530_ovl21(u8* arg0) {
    u8* p;

    if (*(s16*)(arg0 + 0x54) != 0) {
        *(s16*)(arg0 + 0x54) -= 1;
        return;
    }
    p = *(u8**)(arg0 + 0x5C);
    *(s16*)(arg0 + 0x54) = 5;
    *(s32*)(arg0 + 0x8) = *(s32*)(p + 0x18);
    *(s32*)(arg0 + 0xC) = *(s32*)(p + 0x1C);
}
