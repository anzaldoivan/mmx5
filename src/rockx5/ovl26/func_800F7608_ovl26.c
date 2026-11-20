#include "types.h"

void func_800F7608_ovl26(u8* a0) {
    switch (((s8*)a0)[2]) {
    case 1:
        *(s16*)(a0 + 0xA) = *(s16*)(*(u8**)(a0 + 0x8C) + 0xA) + 0xA0;
        *(s16*)(a0 + 0xE) = *(s16*)(*(u8**)(a0 + 0x8C) + 0xE);
        break;
    case 3:
        *(s16*)(a0 + 0xA) = *(s16*)(*(u8**)(a0 + 0x8C) + 0xA) - 0xA0;
        *(s16*)(a0 + 0xE) = *(s16*)(*(u8**)(a0 + 0x8C) + 0xE);
        break;
    }
}
