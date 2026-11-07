#include "types.h"

extern void func_8002C1C8(void);
extern u8* func_8002D53C(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A1F8[];
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8* D_800FBC88_ovl50;

void func_800FAC60_ovl50(u8* arg0) {
    u8* p;
    u8* o;

    if (D_80091C44 == 0) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        p = D_8009A1F8;
        *(s32*)(p + 0xB4) = 0x02000000;
        p[3] = 0;
        p[0x57] = 0;
        p[0xF4] = 1;
        ((s32*)p)[0x2C] = 0;
        D_800FBC88_ovl50[0x36] = 0x32;
        o = func_8002D53C();
        if (o != 0) {
            o[0] = 1;
            o[1] = 9;
            o[0x36] = 0x11;
            *(s16*)(o + 0x34) = 0x7FFF;
            o[2] = 2;
            *(s32*)(o + 0x38) = 0x1E;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}
