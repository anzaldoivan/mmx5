#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern void func_8002C1C8(void);
extern u8 D_8009A1F8[];
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];

void func_800FA2F8_ovl58(u8* arg0) {
    u8* p = D_8009A1F8;

    p[0xA0] = 1;
    *(s32*)(p + 0x60) += 0xFFFDDDDE;
    if (++*(s16*)(arg0 + 4) >= 60) {
        *(s16*)(p + 0x62) = 0x4E0;
        p[0xA0] = 1;
        func_8002385C(0x77, 0xFF, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
        func_8002C1C8();
        D_800D50DC = 0;
        D_8009A42C = 1;
        D_80093E66 = 1;
        D_80093DD0[0] = -1;
        D_80093DD0[1] = -1;
        D_80093DD0[2] = -1;
        D_80093DD0[3] = -1;
        D_80093DD0[4] = -1;
        D_80093DD0[5] = -1;
        D_80093DD0[6] = -1;
        D_80093DD0[7] = -1;
        D_80093DD0[8] = -1;
        D_80093DD0[9] = -1;
    }
}
