#include "types.h"

extern int func_8002D6FC();
extern u8 D_800D1C00[];

void func_800F4AD4_ovl06(u8* obj) {
    u8* p;

    obj[3] = 0;
    if (--*(s16*)(obj + 0x7C) == 0) {
        p = D_800D1C00;
        p[0x26] |= 8;
        func_8002D6FC();
    }
}
