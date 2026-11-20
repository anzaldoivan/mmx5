#include "types.h"

extern s16 D_8009A1F8[];
extern s8 D_800D1C26;
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void func_8002B070(s32, s32, s32, s32, s32);

void func_800EED00_ovl02(u8* arg0) {
    if (++*(s16*)(arg0 + 0x14) == 0xB2) {
        func_8002B070(D_8009A1F8[5] - 0x30, D_8009A1F8[5] + 0x170,
                      D_8009A1F8[7] - 0x30, D_8009A1F8[7] + 0x120, 0);
    }
    if (*(s16*)(arg0 + 0x14) >= 0xB5) {
        D_800D1C26 = 1;
        *(s16*)(arg0 + 0x14) = 0;
        arg0[4]++;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
    }
}
