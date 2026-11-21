#include "types.h"
#include "mmx5/ovl50.h"
#include "mmx5/globals.h"
#define D_800FBC88_ovl50_as_AB ((D_8009A1F8_AB_t*)D_800FBC88_ovl50)

extern u8 D_80091C44;
extern D_8009A1F8_AB_t D_8009A1F8;

void func_800FA780_ovl50(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.unk8 = 0x80000;
        D_8009A1F8.unkC = 0x800000;
        D_8009A1F8.unk4C = 1;
        D_8009A1F8.unk57 = 0;
        D_8009A1F8.unkB0 = 0;
        D_8009A1F8.unkB4 = 0;
        D_8009A1F8.unkF4 = 1;
        D_8009A1F8.unkAB = 1;
        D_800FBC88_ovl50_as_AB->unk3 = 1;
        D_800FBC88_ovl50_as_AB->unk36 = 2;
        arg0->unk4 = 0;
        D_8009A1F8.unk3 = 0;
        func_8002385C(0x29, 0xFF, 0);
        arg0->unk1++;
    }
}
