#include "types.h"

extern s8* D_80102FD8_ovl04;
extern s8 D_800D1C1D;
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern void func_8003B65C(void*);

void func_800EFED8_ovl04(u8* a0) {
    u8* p;

    if (*D_80102FD8_ovl04 == 0) {
        D_800D1C1D = 4;
        func_8003B65C(D_8009A0A0);
        p = D_8009A1F8;
        *(s16*)(p + 0x2A) = 0x2D0;
        *(s16*)(p + 0x22) = 0x2D0;
        a0[6] = 0;
        a0[5]++;
    }
}
