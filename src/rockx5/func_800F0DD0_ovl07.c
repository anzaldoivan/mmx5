#include "types.h"

extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern u16 D_80093E68;
extern s32 func_80016490(s32, s32, void*);
extern void func_8002C218(void);
extern void func_8002DF54(u8* a0);

void func_800F0DD0_ovl07(u8* arg0) {
    if (*(s16*)(arg0 + 0xA) >= 0x1EFB) {
        func_80016490(5, 0x14, 0);
        arg0[5]++;
        *(s16*)(arg0 + 0x9C) = 0;
        func_8002C218();
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_800D50DE = 0x1F;
        D_8009A42E = 0x3E0;
        D_80093E68 = 0x7C00;
    } else {
        func_8002DF54(arg0);
    }
}
