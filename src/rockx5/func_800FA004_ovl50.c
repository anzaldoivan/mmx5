#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8002385C(s32, s32, s32);
extern s32 D_80093DD0[];
extern u8 D_80093E66;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];
extern u8 D_8009A42C;
extern u16 D_8009A42E;
extern u8 D_800D50DC;
extern u16 D_800D50DE;

void func_800FA004_ovl50(u8* arg0) {
    u8* p;
    s32* q;
    s32* b;
    s32 i;
    s32 m;

    if (++*(u16*)(arg0 + 6) & 1) {
        u8* p1 = D_8009A1F8;
        *(s16*)(p1 + 0xB6) = func_8002DF78() % 5 + 0x104;
    } else {
        u8* p2 = D_8009A1F8;
        *(s16*)(p2 + 0xB6) = 0x100;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0x60) += 0xFFFBBBBC;
    if (++*(s16*)(arg0 + 4) >= 0x1E) {
        *(s32*)(p + 0x60) = 0x1000000;
        func_8002385C(0x3A, 0xFF, 0);
        m = -1;
        b = D_80093DD0;
        q = b + 2;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        for (i = 13; i >= 0; i--) {
            *q++ = m;
        }
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
