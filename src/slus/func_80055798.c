#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D29C(s32, s32);
extern u8 D_8009A0A0[];

void func_80055798(u8* obj) {
    u8* p = D_8009A0A0;
    s16 d;

    d = *(u16*)(p + 0xA) - *(u16*)(obj + 0xA);
    if (d < 0) {
        d = -d;
    }
    if (d < 0x41) {
        d = *(u16*)(p + 0xE) - *(u16*)(obj + 0xE);
        if (d > 0) {
            if (d >= 0x11) {
                return;
            }
        } else {
            d = -d;
            if (d >= 0x69) {
                return;
            }
        }
        func_800171E8(obj, 0xA);
        if (*(s32*)(p + 8) - *(s32*)(obj + 8) > 0) {
            func_8003D29C(0x14, 0);
            obj[0x15] = 0x40;
        } else {
            func_8003D29C(0x14, 0x40);
            obj[0x15] = 0;
        }
        obj[6] = 0;
        obj[5]++;
    }
}
