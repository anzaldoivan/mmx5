#include "types.h"

extern void func_80012BF4(s32);
extern s32 func_80016490(s32, s32, void*);

void func_800FBCEC_ovl27(u8* a0) {
    if (((s8*)a0)[6] == 0) {
        if (((s8*)a0)[2] == 0) {
            func_80012BF4(7);
            func_80016490(2, 0x68, 0);
            *(s32*)(a0 + 0x20) = -0x8000;
            *(s16*)(a0 + 0x80) = 0x20;
        } else {
            *(s32*)(a0 + 0x20) = 0x8000;
        }
        *(s32*)(a0 + 0x24) = 0;
        a0[6]++;
    }
}
