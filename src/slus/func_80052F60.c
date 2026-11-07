#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s16 D_8009A0AA;
extern u8 D_8009A1F8[];

void func_80052F60(u8* obj) {
    s16 x;
    s32 d;
    u8* p;

    x = *(s16*)(obj + 0xA);
    p = D_8009A1F8;
    obj[3] = 0;
    d = x - *(s16*)(p + 0xA);
    if (d < 0x20) {
        return;
    }
    if (d >= 0x121) {
        return;
    }
    {
        d = *(s16*)(obj + 0xE) - *(s16*)(p + 0xE);
        if (d < 0x20) {
            return;
        }
        if (d >= 0xD1) {
            return;
        }
        {
            if (D_8009A0AA < x) {
                obj[0x84] = 0;
                obj[0x15] = 0;
            } else {
                obj[0x84] = 1;
                obj[0x15] = 0x40;
            }
            if (((s8*)obj)[2] == 1) {
                func_800171E8(obj, 5);
            } else {
                func_800171E8(obj, 0);
            }
            obj[6]++;
        }
    }
}
