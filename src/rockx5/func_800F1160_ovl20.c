#include "types.h"

extern u8* func_8002D53C(void);
extern u8 D_8009A1F8[];
extern s8 D_800D1C28[];

void func_800F1160_ovl20(u8* arg0) {
    u8* b;
    u8* c;
    u8* p;

    b = D_8009A1F8;
    if (*(s16*)(b + 0x5E) < 0x281) {
        *(s16*)(b + 0x5E) -= 8;
    } else {
        *(s16*)(b + 0x5E) += 8;
    }
    c = D_8009A1F8;
    if ((u16)(*(u16*)(c + 0x5E) - 0x141) >= 0x3BF) {
        *(s16*)(c + 0x5E) = 0x140;
        c[0xA0] = 1;
        arg0[2]++;
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0xC;
            p[2] = 0x50;
        }
        D_800D1C28[1] = 1;
    }
}
