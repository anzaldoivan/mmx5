#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_800FC500_ovl56[];
extern u8 D_800FC300_ovl56[];
extern u8 D_8009A1F8[];

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800FAB90_ovl56(u8* e) {
    u8* p;

    if (D_800D1F3C == 2) {
        func_8002C3CC(D_800FC500_ovl56, D_800FC300_ovl56, 0x100,
                      0x3C - *(s16*)(e + 4), 0x3C);
        func_8002C338(0x50, D_800FC500_ovl56, 0x10);
        p = D_8009A1F8;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0;
        p[0xA0] = 1;
        e[1]++;
    }
}
