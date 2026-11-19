#include "types.h"

extern void func_8002C1C8(void);
extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DDC;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern u8 D_8009A1F8[];

void func_800FA65C_ovl57(u8* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DDC = 0xFFFF0000;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        p = D_8009A1F8;
        p[0x3] = 0;
        p[0x57] = 0;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x100;
        p[0xF4] = 1;
        arg0[1]++;
    }
}
