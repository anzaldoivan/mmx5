#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;

void func_800FA2A4_ovl45(u8* arg0) {
    u16 n;

    if (++*(s16*)(arg0 + 4) >= 4) {
        n = ++D_800D50DE;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        *(s16*)(arg0 + 4) = 0;
        if (n == 0x1F) {
            func_8002385C(0x16, 0xFF, 0);
            arg0[1]++;
        }
    }
}
