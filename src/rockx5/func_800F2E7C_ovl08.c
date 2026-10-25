#include "types.h"

extern u8 D_8009A0A0[];
extern s32 func_80016490(s32, s32, void*);

void func_800F2E7C_ovl08(u8* a0) {
    u8* p = D_8009A0A0;

    if (*(s16*)(p + 0xA) >= 0x196) {
        *(s16*)(p + 0xA) = 0x195;
    }
    if (*(s8*)(a0 + 0x45) == 1) {
        func_80016490(5, 0x15, a0);
        a0[5] = 2;
        a0[6] = 0;
    }
}
