#include "types.h"

extern void func_80032CEC();
extern s16 D_800F55D8_ovl20[][2];

void func_800F2E9C_ovl20(u8* obj) {
    u8 t;

    t = obj[2];
    obj[0x37] = 1;
    *(s16*)(obj + 0xA) = D_800F55D8_ovl20[t & 0xF][0];
    *(s16*)(obj + 0xE) = D_800F55D8_ovl20[t & 0xF][1];
    *(s16*)(obj + 0x16) = 0;
    *(s16*)(obj + 0x1A) = 0;
    *(s16*)(obj + 0x1E) = 0x40;
    *(s16*)(obj + 0x22) = 0;
    *(s16*)(obj + 0x26) = 0x40;
    *(s16*)(obj + 0x2A) = 0x30;
    *(s16*)(obj + 0x2E) = 0;
    *(s16*)(obj + 0x32) = 0x30;
    if ((s8)t >= 0x10) {
        *(s16*)(obj + 0x34) = 0x294A;
        obj[0x36] = 5;
        obj[5] = 1;
    } else {
        *(s16*)(obj + 0x34) = 0x7FFF;
        obj[0x36] = 0x20;
        obj[5] = 0;
        func_80032CEC(obj);
    }
    obj[2] = obj[2] & 0xF;
    obj[4] = obj[4] + 1;
}
