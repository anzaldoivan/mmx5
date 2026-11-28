#include "types.h"
#include "mmx5/globals.h"

void func_800F02CC_ovl04(void) {
    u8* a = g_Player;
    u8* b = D_8009A1F8.u;
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
