#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern u16 D_8009A22C;
extern s32 D_8009A420;
extern u8 D_800D1C2A;

void func_800FDC40_ovl04(u8* obj) {
    u8* p;

    *(s32*)(obj + 8) += 0xFFFF0000;
    *(s32*)(obj + 0xC) += 0x3000;
    if (*(s16*)(obj + 0xA) >= 0x1AF) {
        if (D_8009A22C == 0) {
            func_8002A600(0x30, 3, 2);
        }
    } else if (D_8009A22C == 0) {
        func_8002A600(0x20, 2, 1);
    }
    if (!(D_8009A420 & 7) && (func_8002DF78() & 0x10)) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = obj;
        }
    }
    if (*(s16*)(obj + 0xA) < 0x188) {
        obj[5] = 0;
        obj[4]++;
        D_800D1C2A = 8;
    }
}
