#include "types.h"

void func_800F3470_ovl20(u8* arg0) {
    s8 state;
    u8* src;

    state = arg0[2];
    src = *(u8**)(arg0 + 0x5C);
    switch (state) {
    case 1:
        *(u16*)(arg0 + 0x16) = *(u16*)(src + 0x16);
        *(u16*)(arg0 + 0x1E) = *(u16*)(src + 0x1E);
        *(u16*)(arg0 + 0x26) = *(u16*)(src + 0x26);
        *(u16*)(arg0 + 0x2E) = *(u16*)(src + 0x2E);
        *(u16*)(arg0 + 0xE) = *(u16*)(src + 0xE) + *(u16*)(src + 0x1A);
        break;
    case 2:
        *(u16*)(arg0 + 0x1A) = *(u16*)(src + 0x1A);
        *(u16*)(arg0 + 0x22) = *(u16*)(src + 0x22);
        *(u16*)(arg0 + 0x2A) = *(u16*)(src + 0x2A);
        *(u16*)(arg0 + 0x32) = *(u16*)(src + 0x32);
        *(u16*)(arg0 + 0xA) = *(u16*)(src + 0xA) + *(u16*)(src + 0x16);
        break;
    case 3:
        *(u16*)(arg0 + 0x1A) = *(u16*)(src + 0x1A);
        *(u16*)(arg0 + 0x22) = *(u16*)(src + 0x22);
        *(u16*)(arg0 + 0x2A) = *(u16*)(src + 0x2A);
        *(u16*)(arg0 + 0x32) = *(u16*)(src + 0x32);
        *(u16*)(arg0 + 0xA) = *(u16*)(src + 0xA) + *(u16*)(src + 0x1E);
        break;
    case 4:
        *(u16*)(arg0 + 0x16) = *(u16*)(src + 0x16);
        *(u16*)(arg0 + 0x1E) = *(u16*)(src + 0x1E);
        *(u16*)(arg0 + 0x26) = *(u16*)(src + 0x26);
        *(u16*)(arg0 + 0x2E) = *(u16*)(src + 0x2E);
        *(u16*)(arg0 + 0xE) = *(u16*)(src + 0xE) + *(u16*)(src + 0x2A);
        break;
    }
}
