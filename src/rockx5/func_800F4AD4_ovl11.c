#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern s16 D_8009A0AA;
extern u8 D_8009A1F8[];

void func_800F4AD4_ovl11(u8* arg0) {
    u8* p;

    if (D_8009A0AA >= 0x849) {
        func_8003D29C(0x14, 0x40);
        p = D_8009A1F8;
        *(s16*)(p + 0x26) = 0x780;
        *(s16*)(p + 0x28) = 0x780;
        *(s16*)(p + 0x2A) += 0x2B;
        arg0[6] = 1;
    }
}
