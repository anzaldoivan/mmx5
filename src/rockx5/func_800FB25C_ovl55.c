#include "types.h"

extern u8 D_80091C44;
extern u8 D_800FD0B8_ovl55[];
extern u8 D_800FCEB8_ovl55[];
extern u8 D_8009A1F8[];

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);

void func_800FB25C_ovl55(u8* e) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        p[0x57] = 1;
        *(s16*)(p + 0x5E) = 0;
        *(s16*)(p + 0x62) = 0x200;
        p[0xA0] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x200;
        p[0xF4] = 1;
        *(s16*)(e + 4) = 0;
        func_8002C3CC(D_800FD0B8_ovl55, D_800FCEB8_ovl55, 0x100, 0x78, 0x78);
        func_8002C338(0xA0, D_800FD0B8_ovl55, 0x10);
        e[1]++;
    }
}
