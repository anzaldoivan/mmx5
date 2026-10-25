#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];

void func_800F02CC_ovl04(void) {
    u8* a = D_8009A0A0;
    u8* b = D_8009A1F8;
    s16 dx = *(u16*)(a + 0xA) - *(u16*)(b + 0xA);
    u16 by = *(u16*)(b + 0xE);

    if ((s16)(*(u16*)(a + 0xE) - by) < -4) {
        *(u16*)(a + 0xE) = by - 4;
    }
    if (dx < 0x2B) {
        *(u16*)(a + 0xA) = *(volatile u16*)(b + 0xA) +
                           0x2B; // !FAKE: volatile forces the reload
    }
}
