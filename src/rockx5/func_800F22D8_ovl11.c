#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8003157C(u8* obj, s16 x, s16 y);

void func_800F22D8_ovl11(u8* o) {
    s16 x;
    s32 vx;

    if (*(s8*)(o + 0x67) != 0) {
        return;
    }
    if (!(o[0x70] & 8)) {
        func_800171E8(o, 0xF);
        D_1F80004C.bytes[0x80] = 5;
        *(s8*)(o + 5) = 3;
        *(s32*)(o + 0x2C) = 0x4200;
        o[6] = 0;
        *(s32*)(o + 0x24) = 0;
        *(s32*)(o + 0x28) = 0;
        *(s8*)(o + 0x67) = -1;
        return;
    }
    if (D_1F80004C.bytes[0x85] == 2) {
        return;
    }
    if (*(s8*)(o + 5) == 6) {
        return;
    }
    if (o[0x15] != 0) {
        x = (*(u8**)(o + 0x68))[2] +
            (*(u16*)(o + 0xA) + (s8)(*(u8**)(o + 0x68))[0]);
    } else {
        x = (*(u16*)(o + 0xA) - (s8)(*(u8**)(o + 0x68))[0]) -
            (*(u8**)(o + 0x68))[2];
    }
    if (func_8003157C(o, x,
                      (*(u8**)(o + 0x68))[3] +
                          (*(u16*)(o + 0xE) + (s8)(*(u8**)(o + 0x68))[1]) +
                          8) != 0) {
        return;
    }
    if (*(s8*)(o + 2) == 0) {
        o[0x15] = (o[0x15] == 0) << 6;
        *(s32*)(o + 0x20) = -*(s32*)(o + 0x20);
        return;
    }
    if (o[0x70] & 3) {
        return;
    }
    func_800171E8(o, 0x19);
    o[5] = 4;
    o[6] = 0;
    if (D_1F80004C.bytes[0x86] == 0) {
        *(s32*)(o + 0x24) = 0x38000;
        vx = -0x10000;
        *(s32*)(o + 0x2C) = 0x4200;
        if (o[0x15] != 0) {
            vx = 0x10000;
        }
        *(s32*)(o + 0x20) = vx;
    } else {
        *(s32*)(o + 0x24) = 0x48000;
        vx = -0x20000;
        *(s32*)(o + 0x2C) = 0x5200;
        if (o[0x15] != 0) {
            vx = 0x20000;
        }
        *(s32*)(o + 0x20) = vx;
    }
    *(s8*)(o + 0x67) = 1;
}
