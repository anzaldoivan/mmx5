#include "types.h"

extern void func_8002C1C8(void);
extern u8* func_8002D53C(void);
extern u16 D_800D50DE;
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u8 D_8009A1F8[];

void func_800FA244_ovl40(u8* arg0) {
    u8* p;
    u8* o;

    D_800D50DE++;
    D_8009A42E += 0x20;
    D_80093E68 += 0x400;
    if (D_800D50DE == 0x1F) {
        p = D_8009A1F8;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x100;
        p[0xF4] = 1;
        func_8002C1C8();
        o = func_8002D53C();
        if (o != 0) {
            o[0] = 1;
            o[1] = 9;
            o[0x36] = 0x11;
            *(s16*)(o + 0x34) = 0;
            o[2] = 0;
            *(s32*)(o + 0x38) = 0x3C;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}
