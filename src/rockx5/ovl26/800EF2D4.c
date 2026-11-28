#include "types.h"
#include "mmx5/globals.h"

#define D_800F4828_ovl05 D_800F8C4C_ovl26

#define func_800EEABC_ovl05 func_800EF2D4_ovl26
#include "shared/func_800EEABC_ovl05.c"
#undef func_800EEABC_ovl05
#undef D_800F4828_ovl05

extern s32 func_8002D800(u8* a0);
extern s16 D_8009A0AE;
extern s32 D_800E92F8;
extern s8 D_800D1C1D;

void func_800EF308_ovl26(u8* obj) {
    u8* p;
    s32 y;

    if (func_8002D800(obj) == 0) {
        p = *(u8**)(obj + 0x18);
        y = *(s16*)(p + 0xC);
        if (D_8009A206.s < y) {
            return;
        }
        if (D_8009A0AE < y + 0x30) {
            return;
        }
        func_80028B18(0, *(s16*)(p + 0), *(s16*)(p + 2), p + 4);
        obj[4]++;
        if (((s8*)obj)[2] == 0) {
            D_800E92F8 = 1;
            D_800D1C1D = 1;
        }
    } else {
        func_8002D760(obj);
    }
}

#define D_800EEBA0_ovl00 func_800EF3AC_ovl26
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
