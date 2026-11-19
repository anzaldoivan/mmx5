#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800F5110_ovl28(void) {
    if (D_80091C44 == 0) {
        u8* o = D_800D1C00;
        u8* b = D_8009A1F8;
        o[0xF] = 0x10;
        o[0x24] = 0;
        *(s32*)(o + 0x20) = 0;
        *(u16*)(b + 0x2A) = *(u16*)(b + 0xE);
    }
}
