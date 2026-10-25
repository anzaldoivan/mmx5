#include "types.h"

extern u8 D_8009A0A0[];
extern s32 func_8003D29C(s32, s32);

void func_800FC394_ovl39(u8* a0) {
    u8* p = D_8009A0A0;

    if ((p[0x15] == 0 && *(s16*)(p + 0xA) < 0x1211) ||
        (p[0x15] == 0x40 && *(s16*)(p + 0xA) >= 0x1210)) {
        func_8003D29C(0x14, D_8009A0A0[0x15]);
        a0[6]++;
    }
}
