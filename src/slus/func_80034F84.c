#include "types.h"

extern s8 D_8009A424;
extern u8 D_800D1C00[];
extern s8 D_800D1C01;
extern s32 D_8009A1F0;
extern s32 D_80091D54;
extern void func_800272B4(void);

void func_80034F84(u8* a0) {
    u8* p;

    if (D_8009A424 == 0) {
        if (*(s32*)(a0 + 0x38) == 0) {
            D_800D1C01 = 0;
        } else {
            p = D_800D1C00;
            p[0x27] = 2;
            p[0] = 0xB;
            p[1] = 0;
            p[2] = 0;
            p[0x10] = 0;
            p[0x11] = 0;
            p[0x12] = 0;
            p[0x13] = 0;
            p[0x14] = 0;
            p[0x15] = 0;
            p[0x16] = 0;
            p[0x17] = 0;
            D_80091D54 = 0;
            *(s32*)(p + 0xB0) += D_8009A1F0;
        }
        a0[4] = 0;
        a0[5] = 0;
    }
    if (*(s32*)(a0 + 0x38) == 0) {
        func_800272B4();
    }
}
