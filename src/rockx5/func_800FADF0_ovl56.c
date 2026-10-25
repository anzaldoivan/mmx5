#include "types.h"

extern u8 D_80091C44;
extern u8 D_800FBF00_ovl56[];
extern u8* D_800FBEF0_ovl56;
extern u8 D_8009A1F8[];
extern u8 D_800FC300_ovl56[];

s32 func_8002C338(s32, void*, s32);

void func_800FADF0_ovl56(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        D_800FBEF0_ovl56[0x36] = 0x21;
        p[3] = 0;
        func_8002C338(0x40, D_800FBF00_ovl56, 0x10);
        func_8002C338(0x50, D_800FC300_ovl56, 0x10);
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x100;
        p[0xA0] = 1;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
