#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80012BF4(s32);
extern u8 D_8009A0A0[];

void func_800FBADC_ovl27(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[2] == 0) {
        p = D_8009A0A0;
        if ((u32)(p[0xFA] - 2) < 2) {
            if (((s8*)p)[0xF3] == 0) {
                func_80016490(2, 0x68, 0);
                func_80012BF4(7);
            }
            arg0[0x82] = p[0xF3];
        } else {
            func_80016490(2, 0x68, 0);
            func_80012BF4(7);
        }
        *(s32*)(arg0 + 0x20) = 0x8000;
        *(s16*)(arg0 + 0x80) = 0x20;
    } else {
        *(s32*)(arg0 + 0x20) = -0x8000;
    }
    *(s32*)(arg0 + 0x24) = 0;
    arg0[6]++;
}
