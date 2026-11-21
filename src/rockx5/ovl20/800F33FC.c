#include "types.h"

extern void (*D_800F5650_ovl20[])(u8*);

void func_800F33FC_ovl20(u8* arg0) {
    u16 x;
    u16 y;

    D_800F5650_ovl20[(signed char)arg0[6]](arg0);
    x = *(u16*)(arg0 + 0x38);
    y = *(u16*)(arg0 + 0x3A);
    *(s16*)(arg0 + 0x16) = -x;
    *(s16*)(arg0 + 0x2E) = -x;
    *(s16*)(arg0 + 0x1E) = x;
    *(s16*)(arg0 + 0x26) = x;
    *(s16*)(arg0 + 0x1A) = -y;
    *(s16*)(arg0 + 0x22) = -y;
    *(s16*)(arg0 + 0x2A) = y;
    *(s16*)(arg0 + 0x32) = y;
}

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
