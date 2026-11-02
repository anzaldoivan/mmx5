#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s16 D_8009A0AA;
extern u8 D_800FE914_ovl06[];
extern u8 D_800FE918_ovl06[];

static inline u8 func_800F4F10_ovl06_face(u8* o) {
    u8 t;

    if (((s8*)o)[2] == 0) {
        t = o[0x8A];
        if (t != 0) {
            if (t & 1) {
                o[0x15] = 0x40;
            } else {
                o[0x15] = 0;
            }
            return 1;
        }
    } else if (*(s16*)(o + 0xA) - D_8009A0AA < 0) {
        o[0x15] = 0x40;
    } else {
        o[0x15] = 0;
    }
    return 0;
}

void func_800F4F10_ovl06(u8* o) {
    if (((s8*)o)[6] == 0) {
        o[6]++;
        func_800171E8(o, 1);
        *(s16*)(o + 0x84) = 0x160;
        func_800F4F10_ovl06_face(o);
        *(u8**)(o + 0x54) = D_800FE914_ovl06;
        *(u8**)(o + 0x50) = D_800FE918_ovl06;
        o[0x60] = 5;
        o[0x8D] &= 0xF3;
    }
    if (!(o[0x70] & 8)) {
        o[5] = 4;
        o[6] = 0;
        return;
    }
    {
        if (!(o[0x8D] & 2)) {
            if (func_800F4F10_ovl06_face(o) == 0) {
                o[5] = 2;
                o[6] = 0;
                o[0x88] = 0;
                o[0x86] = 0;
                o[0x87] = 0;
                *(u8**)(o + 0x54) = D_800FE914_ovl06;
                *(u8**)(o + 0x50) = D_800FE918_ovl06;
                o[0x60] = 5;
                return;
            }
            if (o[0x86] != 0) {
                o[5] = 8;
                o[6] = 0;
                return;
            }
            if (o[0x87] != 0) {
                o[5] = 9;
                o[6] = 0;
                return;
            }
            if (o[0x15] != 0) {
                *(s32*)(o + 0x20) = 0x16000;
            } else {
                *(s32*)(o + 0x20) = 0xFFFEA000;
            }
            *(s32*)(o + 8) += *(s32*)(o + 0x20);
            func_80017248(o);
        } else {
            func_80017248(o);
        }
    }
}
