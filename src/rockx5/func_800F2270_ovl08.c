#include "types.h"

extern s32 func_800317B8(u8* a0);

void func_800F2270_ovl08(u8* a0) {
    u8* p = *(u8**)(a0 + 0x7C);

    if (*(s8*)(p + 4) == 2) {
        a0[4]++;
    }
    *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(a0 + 0xE) = *(u16*)(p + 0xE);
    func_800317B8(a0);
}
