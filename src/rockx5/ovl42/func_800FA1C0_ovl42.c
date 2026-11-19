#include "types.h"
#include "mmx5/globals.h"

extern u8 D_8009A1F8[];
extern s32 D_800FA43C_ovl42;

void func_800FA1C0_ovl42(u8* arg0) {
    u8* p = D_8009A1F8;

    *(s32*)(p + 0xB4) += 0x15555;
    if (++*(s16*)(arg0 + 4) >= 0x60) {
        *(s16*)(p + 0xB6) = 0x80;
        D_800FA43C_ovl42 = 0x700000;
        *(s16*)(arg0 + 4) = 0x3C;
        p[0x3] = 0;
        *(s16*)(p + 0x62) = 0;
        *(s16*)(p + 0x5E) = 0x200;
        *(s32*)(p + 0x5C) += 0x700000;
        p[0xA0] = 1;
        p[0x57] = 1;
        func_8002385C(0xC, 0xFF, 0);
        arg0[1]++;
    }
}
