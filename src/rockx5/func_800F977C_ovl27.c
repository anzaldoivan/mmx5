#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800767E0[];
extern u8 D_800FDBD0_ovl27[];
extern u8 D_800FDBD4_ovl27[];

void func_800F977C_ovl27(u8* obj) {
    s8 kind;
    u8* src;

    kind = ((s8*)obj)[2];
    obj[0x75] = 1;
    obj[0xA2] = 1;
    obj[0x76] = 0;
    obj[0x67] = 0;
    if (kind < 2) {
        obj[0x16] = 3;
        obj[0x60] = 0x1E;
        obj[0x5C] = 0;
        obj[0x61] = 0;
        obj[0x65] = 0;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x58) = D_800767E0;
        *(u8**)(obj + 0x54) = D_800FDBD0_ovl27;
        *(u8**)(obj + 0x68) = D_800FDBD4_ovl27;
        obj[3] = 1;
        if (kind == 0) {
            obj[0x15] = 0;
            func_800171E8(obj, 1);
            *(s16*)(obj + 0xA) = 0x1268;
            *(s16*)(obj + 0xE) = 0x70;
            *(s16*)(obj + 0x8) = 0;
            obj[5] = 0;
        } else if (kind == 1) {
            obj[0x15] = 0;
            func_800171E8(obj, 0);
            *(s16*)(obj + 0xA) = 0x1418;
            *(s16*)(obj + 0xE) = 0x70;
            *(u16*)(obj + 0x8) = 0x8000;
            obj[5] = 0;
        }
    } else if (kind == 2) {
        obj[3] = 0;
        src = *(u8**)(obj + 0x7C);
        *(u8**)(obj + 0x68) = *(u8**)(src + 0x68);
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
        obj[5] = 4;
    } else if (kind == 3) {
        ((s8*)obj)[0x66] = -1;
        obj[3] = 0;
        src = *(u8**)(obj + 0x7C);
        *(u8**)(obj + 0x68) = *(u8**)(src + 0x68);
        *(s16*)(obj + 0xA) = *(s16*)(src + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(src + 0xE);
        obj[5] = 4;
    }
    obj[6] = 0;
    obj[4]++;
}
