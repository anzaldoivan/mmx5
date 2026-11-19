#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern u8 D_80091C44;
extern void func_8002C1C8(void);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DD8;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;

void func_800FA820_ovl52(u8* arg) {
    u8* p;

    if (D_80091C44 == 0) {
        p = (u8*)&D_8009A1F8;
        p[0xAB] = 1;
        *(u16*)(p + 0xB6) = 0x100;
        *(u16*)(p + 0xB2) = 0;
        p[0xF4] = 1;
        D_80093E66 = 1;
        D_8009A42C = 1;
        D_800D50DC = 1;
        func_8002C1C8();
        D_80093DD8 = 0xFFFF;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
        arg[1]++;
    }
}
