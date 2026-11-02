#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_800FCD00_ovl56[];
extern u8 D_800FCB00_ovl56[];
extern u8 D_800FD100_ovl56[];
extern u8 D_800FCF00_ovl56[];

void func_8002C1C8(void);
void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
void func_8002385C(s32, s32, s32);

void func_800FA834_ovl56(Ovl45State* arg0) {
    u8* g = D_8009A1F8;

    g[0xF4] = 1;
    *(s32*)(g + 0xB0) += 0x22222;
    arg0->unk4++;
    if (arg0->unk4 >= 0x5A) {
        func_8002C1C8();
        *(s16*)(g + 0xB2) = 0xC0;
        g[0xF4] = 1;
        arg0->unk4 = 0;
        func_8002C3CC(D_800FCD00_ovl56, D_800FCB00_ovl56, 0x100, 0x5A, 0x5A);
        func_8002C338(0x130, D_800FCD00_ovl56, 0x10);
        func_8002C3CC(D_800FD100_ovl56, D_800FCF00_ovl56, 0x100,
                      0x5A - arg0->unk4, 0x5A);
        func_8002C338(0x140, D_800FD100_ovl56, 0x10);
        arg0->unk1++;
        func_8002385C(0x6C, 0xFF, 0);
    }
}
