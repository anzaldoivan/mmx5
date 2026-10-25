#include "types.h"

extern s32 func_80044DE0();
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_800FEB60_ovl39[];
extern u8 D_8009A1F8[];

void func_800FC500_ovl39(u8* arg0) {
    if (func_80044DE0() == 0) {
        func_80028B18(0, 0x1170, 0x790, D_800FEB60_ovl39);
        D_8009A1F8[0x3] = 1;
        D_8009A1F8[0x57] = 1;
        D_8009A1F8[0xAB] = 1;
        D_8009A1F8[0x58] = 2;
        *(s16*)(D_8009A1F8 + 0x94) = 0;
        *(s16*)(D_8009A1F8 + 0x96) = 0;
        D_8009A1F8[0xA0] = 1;
        D_8009A1F8[0x4C] = 1;
        arg0[6]++;
    }
}
