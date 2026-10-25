#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern void func_8002C218(void);
extern u8* func_8002D144(void);
extern u8 D_800FB46C_ovl00[];
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_800FB698_ovl00;

void func_800F82E8_ovl00(u8* arg0) {
    u8* p;
    u8* b;

    func_8002A600(0x10, 6, 3);
    b = D_800FB46C_ovl00;
    *(s16*)(b + 0xC) = 0;
    *(s16*)(b + 0x1A) = 0;
    *(s16*)(b + 0x28) = 0;
    *(s16*)(b + 0x36) = 0;
    D_800D50DC = 0;
    D_8009A42C = 0;
    D_80093E66 = 0;
    func_8002C218();
    *(s16*)(arg0 + 0x7E) = 0;
    *(s16*)(arg0 + 0x7C) = 0x10;
    *(s16*)(arg0 + 0xA) -= 0x20;
    D_800FB698_ovl00 = 0;
    arg0[6]++;
    p = func_8002D144();
    if (p != 0) {
        p[0] = 1;
        p[1] = 3;
        p[2] = 3;
    }
}
