#include "types.h"

extern s32 func_8003D2C4(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C26;
extern s32 D_800E92F8;

void func_800EFD94_ovl04(u8* arg0) {
    u8* p;

    if (D_800D1C26 & 4) {
        D_800E92F8 = 1;
        p = D_8009A1F8;
        *(s16*)(p + 0x24) = 0xC80;
        func_8003D2C4();
        arg0[6]++;
        *(s8*)(p + 0xA6) = -1;
        *(s16*)(p + 0x5E) = 0x370;
        *(s16*)(p + 0x62) = 0x100;
        p[0xA0] = 1;
        arg0[0x1C] = 0;
    }
}
