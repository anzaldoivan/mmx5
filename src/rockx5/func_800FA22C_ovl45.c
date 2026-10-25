#include "types.h"

extern void func_80016490(s32, s32, void*);

extern s32 D_80093DD8;

void func_800FA22C_ovl45(u8* arg0) {
    if (++*(s16*)(arg0 + 4) == 30) {
        func_80016490(2, 0x4C, 0);
    }
    if (*(s16*)(arg0 + 4) >= 50) {
        D_80093DD8 = 0xFFFF0000;
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
