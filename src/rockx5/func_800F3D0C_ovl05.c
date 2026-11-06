#include "types.h"

extern s16 D_8009A202;
extern s32 D_8009A420;
extern u8* func_8002D27C(void);
extern void func_8002A600(s32, s32, s32);

void func_800F3D0C_ovl05(u8* o) {
    u8* p;

    if (++*(s16*)(o + 0x7C) >= 0xB4) {
        *(s16*)(o + 0x7C) = 0;
        o[6] = 0;
        o[5]++;
    }
    *(s16*)(o + 0xA) = D_8009A202 - 0x10;
    if (!(D_8009A420 & 3)) {
        p = func_8002D27C();
        if (p != 0) {
            *(u8**)(p + 0x50) = o;
            p[0] = 0x41;
            p[1] = 0x14;
            p[2] = 4;
        }
    }
    if (!(D_8009A420 & 0x1F)) {
        func_8002A600(0xA, 1, 1);
    }
}
