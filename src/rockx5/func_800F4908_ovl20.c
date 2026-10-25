#include "types.h"

extern int func_8002D6FC();
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_800D1C00[];
extern u16 D_800F596C_ovl20[][2];

void func_800F4908_ovl20(u8* a0) {
    u8* p = D_800D1C00;

    if (((s8*)p)[0x30] != 0) {
        func_8002D6FC();
    } else {
        *(u16*)(a0 + 0xA) = D_800F596C_ovl20[((s8*)p)[0x31]][0];
        *(u16*)(a0 + 0xE) = D_800F596C_ovl20[((s8*)p)[0x31]][1] + 5;
        func_8002D9EC(a0, 0x80, 0x40);
    }
}
