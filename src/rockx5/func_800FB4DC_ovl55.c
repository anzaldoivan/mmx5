#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern s32 D_800FD2BC_ovl55;

extern s32 func_80016490(s32, s32, void*);

void func_800FB4DC_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        p[0x57] = 1;
        p[0xA0] = 1;
        p[0xAB] = 1;
        p[0xF4] = 1;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0x200;
        *(s16*)(p + 0xB6) = 0x200;
        p[3] = 0;
        *(s16*)(p + 0xB2) = 0;
        D_800FD2BC_ovl55 = 0;
        func_80016490(2, 0x53, 0);
        *(s16*)(e + 4) = 0;
        e[1]++;
    }
}
