#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);
extern s16 D_8009A0AA;
extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

static inline u8 func_800F5840_ovl06_face(u8* obj) {
    if (*(s8*)(obj + 2) == 0) {
        if (obj[0x8A] != 0) {
            if (obj[0x8A] & 1) {
                obj[0x15] = 0x40;
            } else {
                obj[0x15] = 0;
            }
            return 1;
        }
    } else if (*(s16*)(obj + 0xA) - D_8009A0AA < 0) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    return 0;
}

void func_800F5840_ovl06(u8* obj) {
    s32 v;

    if (*(s8*)(obj + 6) == 0) {
        obj[6] = 1;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0x4200;
        obj[0x67] = 1;
        func_800171E8(obj, 3);
        *(u8**)(obj + 0x54) = D_800FE914_ovl06;
        *(u8**)(obj + 0x50) = D_800FE918_ovl06;
        obj[0x60] = 5;
    }
    if (obj[0x70] & 8) {
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    if (obj[0x8D] & 2) {
        return;
    }
    if (obj[0x87] != 0) {
        obj[5] = 0xA;
        obj[6] = 0;
        return;
    }
    if (*(s8*)(obj + 1) == 0x48 && obj[0x86] != 0) {
        obj[5] = 0xC;
        obj[6] = 0;
        return;
    }
    *(s32*)(obj + 0x20) = 0;
    if (func_800F5840_ovl06_face(obj)) {
        v = *(s16*)(obj + 0x84) << 8;
        if (obj[0x15] == 0) {
            v = -v;
        }
        *(s32*)(obj + 0x20) = v;
    }
    if (*(s32*)(obj + 0x24) < -0x5E000) {
        *(s32*)(obj + 0x24) = -0x5E000;
    }
    func_8002DED4(obj);
}
