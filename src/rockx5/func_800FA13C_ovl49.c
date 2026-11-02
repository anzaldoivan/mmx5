#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80016490(s32, s32, s32, s32);
extern void func_8002385C(s32, s32, s32);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FA13C_ovl49(u8* arg0) {
    u8* p;

    if (++*(u16*)(arg0 + 4) & 1) {
        p = D_8009A1F8;
        *(s16*)(p + 0xA) = 0x2C0 - func_8002DF78() % 5;
        *(s16*)(p + 0xE) = 0x38 - func_8002DF78() % 3;
    } else {
        u8* r = D_8009A1F8;
        *(s16*)(r + 0xA) = 0x2C0;
        *(s16*)(r + 0xE) = 0x38;
    }
    if (D_80091C44 == 0) {
        u8* q = D_8009A1F8;
        s32 one = 1;
        q[3] = 0;
        q[0x57] = 0;
        *(s32*)(q + 0xB0) = 0;
        *(s32*)(q + 0xB4) = 0x02000000;
        q[0xAB] = one;
        q[0xF4] = one;
        func_80016490(2, 0x6C, 0, one);
        func_8002385C(0x2E, 0xFF, 0);
        arg0[1]++;
    }
}
