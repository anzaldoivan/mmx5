#include "types.h"

extern void (*D_8007BA5C[])(u8*);
extern u8 D_800E9598[0x10];
extern s32 D_8009A420;
extern u8 D_8007BA4C[];

void func_80051B48(u8* arg0) {
    D_8007BA5C[*(s8*)(arg0 + 5)](arg0);
    if (*(s8*)(arg0 + 5) != 0 && D_800E9598[0] != 0 && D_8009A420 % 3 == 0) {
        *(s16*)(arg0 + 0x34) = D_8007BA4C[arg0[0x3C]];
        arg0[0x3C]++;
        if (arg0[0x3C] == 14) {
            arg0[0x3C] = 0;
        }
    }
}
