#include "types.h"
#include "mmx5/graphics.h"

extern void func_800FCDB8_ovl38(u8* obj, s32 a, s32 b);
extern u8 D_800FD980_ovl38[];
extern u8 D_800FD984_ovl38[];
extern u8 D_800FD988_ovl38[];
extern u8 D_800FD98C_ovl38[];

void func_800FB0B8_ovl38(u8* o) {
    s32 one;
    s32 t;
    s32 x;

    o[0x67] = 0;
    o[0x16] = 5;
    o[3] = 0;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x24) = 0;
    switch ((s8)o[2]) {
    case 0:
    case 1:
    case 2:
        set_animation(o, 10);
        if (o[0x15] == 0) {
            x = *(u16*)(o + 0xA) - 0x38;
        } else {
            x = *(u16*)(o + 0xA) + 0x38;
        }
        t = *(s32*)(o + 0xC);
        *(s16*)(o + 0xA) = x;
        x = 10;
        *(u8*)(o + 0x60) = x;
        *(u8**)(o + 0x68) = D_800FD980_ovl38;
        *(s16*)(o + 0x90) = 0;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x54) = 0;
        *(u8**)(o + 0x50) = D_800FD984_ovl38;
        o[5] = 0;
        *(s32*)(o + 0x8C) = t;
        break;
    case 3: {
        set_animation(o, 0x11);
        one = 1;
        *(s16*)(o + 0xA) = 0x1278;
        *(s16*)(o + 0xE) = 0x7D8;
        o[0x60] = 0x14;
        o[3] = one;
        o[0x15] = 0;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x68) = 0;
        *(u8**)(o + 0x50) = D_800FD988_ovl38;
        *(s32*)(o + 0x20) = 0xFFFD0000;
        o[5] = one;
        break;
    }
    case 4: {
        set_animation(o, 0x11);
        one = 1;
        *(s16*)(o + 0xA) = 0x1278;
        *(s16*)(o + 0xE) = 0x808;
        o[0x60] = 0x14;
        o[3] = one;
        o[0x15] = 0;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x68) = 0;
        *(u8**)(o + 0x50) = D_800FD988_ovl38;
        *(s32*)(o + 0x20) = 0xFFFD0000;
        o[5] = one;
        break;
    }
    case 5: {
        set_animation(o, 0x11);
        one = 1;
        *(s16*)(o + 0xA) = 0x1278;
        *(s16*)(o + 0xE) = 0x780;
        o[0x60] = 0x14;
        o[3] = one;
        o[0x15] = 0;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x68) = 0;
        *(u8**)(o + 0x50) = D_800FD988_ovl38;
        *(s32*)(o + 0x20) = 0xFFFB0000;
        o[5] = one;
        break;
    }
    case 6: {
        s32 one;

        set_animation(o, 0xF);
        one = 1;
        o[3] = one;
        *(s16*)(o + 0xA) = 0x1278;
        *(s16*)(o + 0xE) = 0x840;
        o[0x60] = 0x14;
        o[0x15] = 0;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x68) = 0;
        *(u8**)(o + 0x50) = D_800FD98C_ovl38;
        *(s32*)(o + 0x20) = 0xFFFB0000;
        o[5] = one;
        func_800FCDB8_ovl38(o, 2, one);
        break;
    }
    case 7:
        o[0] = 0x71;
        *(s16*)(o + 0x42) = 0x7C8C;
        o[0x16] = 7;
        o[3] = 1;
        *(s16*)(o + 0x88) = 0x14;
        o[0x60] = 0xC;
        *(s32*)(o + 0x58) = 0;
        *(s32*)(o + 0x68) = 0;
        o[5] = 2;
        break;
    }
    o[6] = 0;
    o[4]++;
}
