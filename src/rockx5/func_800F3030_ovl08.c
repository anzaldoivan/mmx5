#include "types.h"

extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F3030_ovl08(u8* a0) {
    u8* p = *(u8**)(a0 + 0x50);

    if (((s8*)p)[4] == 2) {
        a0[4] = 2;
        a0[5] = 0;
        a0[3] = 0;
    } else {
        *(s16*)(a0 + 0xA) = *(s16*)(p + 0xA);
        *(s16*)(a0 + 0xE) = *(s16*)(p + 0xE) - 0xA8;
        func_8002D9EC(a0, 0x20, 0x20);
        if (((s8*)a0)[3] == 0) {
            a0[3] = p[3];
        }
    }
}
