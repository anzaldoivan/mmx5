#include "types.h"

extern void func_80017248(u8* obj);

void func_800F62C0_ovl26(u8* obj) {
    s32 speed;
    s32 n;

    if ((*(u8**)(obj + 0x7C))[0x96] == 0) {
        speed = 0x60000;
    } else {
        speed = -0x60000;
    }
    func_80017248(obj);
    obj[6]++;
    n = ((s8*)obj)[2];
    if (n < 8) {
        *(s16*)(obj + 0x90) = (n + 1) * 35;
        *(s32*)(obj + 0x20) = speed;
    } else {
        *(s16*)(obj + 0x90) = (n - 7) * 35;
        *(s32*)(obj + 0x20) = -speed;
    }
}
