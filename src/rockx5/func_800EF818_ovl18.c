#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s8 D_8009A0A5;

void func_800EF818_ovl18(u8* arg0) {
    if (D_8009A0A5 == 0x14) {
        *(s16*)(arg0 + 0x7C) = 0x2A;
        arg0[6]++;
        func_80016490(5, 0x16, arg0);
    }
}
