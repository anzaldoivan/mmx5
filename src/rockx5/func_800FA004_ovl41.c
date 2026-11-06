#include "types.h"

extern u8* func_8002D53C(void);
extern s32 func_8002DF78(void);
extern u8 D_8009A1F8[];
extern u8* D_800FB89C_ovl41;

void func_800FA004_ovl41(u8* arg0) {
    u8* p;
    u8* o;
    u8* q;
    s32 one;
    s32 r;

    p = D_8009A1F8;
    p[3] = 0;
    p[0x57] = 0;
    p[0xAB] = 0;
    o = func_8002D53C();
    D_800FB89C_ovl41 = o;
    if (o != 0) {
        o[0] = 1;
        D_800FB89C_ovl41[1] = 10;
        D_800FB89C_ovl41[0x36] = 50;
        D_800FB89C_ovl41[2] = 0;
    }
    q = func_8002D53C();
    if (q != 0) {
        one = 1;
        q[0] = one;
        q[1] = 9;
        q[0x36] = 0x11;
        *(s16*)(q + 0x34) = 0;
        q[2] = one;
        *(s32*)(q + 0x38) = 60;
    }
    *(s16*)(arg0 + 4) = 1;
    r = func_8002DF78();
    arg0[1]++;
    *(s16*)(arg0 + 6) = (r % 7 + 12) * 5;
}
