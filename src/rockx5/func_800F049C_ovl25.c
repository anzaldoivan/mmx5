#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_8009A1F8[];
extern u8 D_800F20F4_ovl25[];
extern u8 D_800F22F4_ovl25[];

void func_800F049C_ovl25(u8* arg0) {
    u8* p;

    p = D_8009A1F8;
    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += 0x8000;
    func_8002C3CC(D_800F22F4_ovl25, D_800F20F4_ovl25, 0x100,
                  0x40 - ++*(s16*)(arg0 + 4), 0x40);
    func_8002C338(0xA0, D_800F22F4_ovl25, 0x10);
    if (*(s16*)(arg0 + 4) > 0x40) {
        func_8002C338(0xA0, D_800F20F4_ovl25, 0x10);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
