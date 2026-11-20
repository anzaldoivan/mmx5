#include "types.h"

void func_800F173C_ovl05(u8* a0) {
    s8 n;

    switch (*(s8*)(a0 + 2)) {
    case 0:
    case 1:
    case 2:
        n = --*(s8*)(a0 + 0x92);
        if (n <= 0) {
            *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + 60;
        } else {
            *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + (n * 44 + 60);
        }
        break;
    case 3:
    case 4:
    case 5:
        *(u16*)(a0 + 0x88) = *(u16*)(a0 + 0x8A) + 90;
        break;
    }
    a0[6]++;
}
