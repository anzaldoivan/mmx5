#include "types.h"
#include "addr.h"

extern void func_8003D29C(s32, s32);
extern u8 D_8009A0A0[];
extern s16 D_8009A202;

void func_800F84B8_ovl09(u8* a0) {
    u8* p = D_8009A0A0;

    if (p[0x15] == 0) {
        if (*(s16*)(p + 0xA) - D_8009A202 > 0xA0) {
            return;
        }
    } else {
        if (*(s16*)(p + 0xA) - D_8009A202 < 0xA0) {
            return;
        }
    }
    func_8003D29C(0x14, 0x40);
    D_1F80004C.bytes[0x86] = 1;
    *(s16*)(a0 + 0x7C) = 3;
    a0[5]++;
}
