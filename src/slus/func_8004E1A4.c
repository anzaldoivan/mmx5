#include "types.h"

extern void func_8002DED4(u8* obj);
extern u8 D_800D1C00[];

void func_8004E1A4(u8* obj) {
    u8* p;

    if (((s8*)obj)[3] != 0) {
        func_8002DED4(obj);
    } else {
        obj[4] = 2;
        obj[5] = 0;
        p = D_800D1C00;
        if (((s8*)p)[0xC] == 5 && ((s8*)p)[0x1D] == 0) {
            p[0x1C] = 0;
        }
    }
}
