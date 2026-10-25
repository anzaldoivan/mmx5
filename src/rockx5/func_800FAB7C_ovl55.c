#include "types.h"

extern u8 D_80091C44;
extern u8* D_800FBAA8_ovl55;
extern u8* D_800FD2B8_ovl55;
extern u8 D_8009A1F8[];

extern u8* func_8002D53C(void);
extern void func_80016490(s32, s32, void*);

void func_800FAB7C_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        D_800FBAA8_ovl55 = func_8002D53C();
        if (D_800FBAA8_ovl55 != 0) {
            D_800FBAA8_ovl55[0] = 1;
            D_800FBAA8_ovl55[1] = 10;
            D_800FBAA8_ovl55[0x36] = 1;
            D_800FBAA8_ovl55[2] = 0;
            D_800FD2B8_ovl55 = D_800FBAA8_ovl55;
        }
        p = D_8009A1F8;
        p[3] = 0;
        *(s16*)(p + 0xA) = 0;
        *(s16*)(p + 0xE) = 0;
        p[0x4C] = 1;
        *(s16*)(e + 4) = 0;
        *(s16*)(e + 6) = 0;
        e[1]++;
        func_80016490(2, 0x52, 0);
    }
}
