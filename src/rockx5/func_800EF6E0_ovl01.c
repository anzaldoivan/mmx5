#include "types.h"

extern u8 D_8009A0A0[];
extern s16 D_8009A21E;
extern u8 D_8009A1F8[];
extern s32 func_8002A600(s32, s32, s32);

void func_800EF6E0_ovl01(u8* arg0) {
    u8* p = D_8009A0A0;
    u8* q;

    if (((s8*)p)[5] == 0x14) {
        D_8009A21E = 0x1CC0;
        arg0[5]++;
    }
    if (p[0xF7] == 0) {
        q = D_8009A1F8;
        if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(q + 0x34) = 0;
        }
    }
}
