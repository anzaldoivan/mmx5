#include "types.h"

extern void func_80017248(u8* obj);

void func_800F609C_ovl26(u8* obj) {
    s32 n;

    func_80017248(obj);
    if (((s8*)*(u8**)(obj + 0x7C))[7] == 0x10) {
        obj[6]++;
        if (obj[0x94] < 3) {
            n = ((s8*)obj)[2];
            n++;
        } else {
            n = ((s8*)obj)[2];
            if (n >= 8) {
                return;
            }
            n++;
        }
        *(s16*)(obj + 0x90) = n * 35;
    }
}
