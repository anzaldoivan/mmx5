#include "types.h"

extern void func_80017248(u8* obj);

void func_800F2E30_ovl07(u8* obj) {
    s8* p = *(s8**)(obj + 0x7C);

    if (p[5] == 4) {
        if (p[6] < 2) {
            func_80017248(obj);
            *(s32*)(obj + 0x54) = 0;
            *(s32*)(obj + 0x68) = 0;
        } else if (p[6] != 3) {
            obj[6]++;
        }
    }
}
