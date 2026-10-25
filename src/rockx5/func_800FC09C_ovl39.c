#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];
extern void func_8003D29C(s32, s32);
extern void func_8002385C(s32, s32, s32);

void func_800FC09C_ovl39(u8* a0) {
    u8* p = D_8009A1F8;
    u8* q = D_8009A0A0;
    u8* r;

    *(s16*)(p + 0x94) = 0;
    p[0xA0] = 1;
    if (*(s32*)(q + 8) > *(s32*)(a0 + 8)) {
        q[0x15] = 0;
    } else {
        q[0x15] = 0x40;
    }
    r = D_8009A0A0;
    func_8003D29C(0x49, r[0x15]);
    if ((s8)r[5] == 0x49) {
        func_8002385C(0x4A, 0xFF, 0);
        a0[5]++;
    }
}
