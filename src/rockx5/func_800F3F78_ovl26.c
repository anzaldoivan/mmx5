#include "types.h"
#include "addr.h"

extern s32 func_80044DE0();
extern s32 func_8003D2C4(void);
extern u8 D_8009A1F8[];
extern signed char D_800D1CA2;

void func_800F3F78_ovl26(u8* a0) {
    u8* g;

    if (func_80044DE0(a0) == 0) {
        g = D_8009A1F8;
        *(s16*)(g + 0x26) = 0x8B0;
        if ((s8)++a0[0x5C] == D_800D1CA2) {
            D_1F80004C.bytes[0x95] = D_800D1CA2;
            g[0x48] = 8;
            *(s32*)(a0 + 0x8C) = 0;
            *(s32*)(a0 + 0x90) = 0;
            D_1F80004C.bytes[0x8D] = 1;
            func_8003D2C4();
            a0[6]++;
        }
    }
}
