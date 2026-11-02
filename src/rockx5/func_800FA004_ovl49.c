#include "types.h"

extern s32 func_8002DF78(void);
extern void func_8002385C(s32, s32, s32);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];

void func_800FA004_ovl49(u8* arg0) {
    u8* p;

    if (++*(u16*)(arg0 + 6) & 1) {
        u8* p1 = D_8009A1F8;
        *(s16*)(p1 + 0xB6) = func_8002DF78() % 5 + 0x104;
    } else {
        u8* p2 = D_8009A1F8;
        *(s16*)(p2 + 0xB6) = 0x100;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0x5C) += 0xAAAAA;
    if (++*(s16*)(arg0 + 4) >= 0x1E) {
        *(s32*)(p + 0x5C) = 0x2000000;
        p[0xAB] = 0;
        *(s32*)(p + 0x8) = 0x3300000;
        *(s32*)(p + 0xC) = 0x380000;
        p[0x3] = p[0x4C] = 1;
        *(s16*)(arg0 + 4) = 0;
        func_8002385C(0x2C, 0xFF, 0);
        func_80016490(2, 0x6C, 0);
        func_80016490(2, 0x50, 0);
        arg0[1]++;
    }
}
