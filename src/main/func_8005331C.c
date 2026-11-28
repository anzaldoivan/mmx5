#include "types.h"

extern u8 D_8007BD24[];
extern u8 D_8007BD20[];

void func_8005331C(u8* a0) {
    if (((s8*)a0)[0x45] == 2) {
        *(u8**)(a0 + 0x54) = D_8007BD24;
        *(u8**)(a0 + 0x50) = D_8007BD20;
    }
    if (((s8*)a0)[0x45] == 1) {
        if (((s8*)a0)[2] == 1) {
            a0[5] = 3;
        } else {
            a0[5] = 4;
        }
        a0[6] = 0;
    }
}
