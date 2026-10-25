#include "types.h"

extern s8 D_800D1D0E;
extern u8 D_800942A8[];
extern void func_80022AA0(u8* p);

void func_80022EDC(void) {
    u8* p;

    if (D_800D1D0E == 0) {
        p = D_800942A8;
        func_80022AA0(p);
        p += 0x50;
        func_80022AA0(p);
        p += 0x50;
        if (*(s8*)p != 0) {
            func_80022AA0(p);
        }
    }
}
