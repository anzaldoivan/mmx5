#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl50.h"
#define D_800FBC88_ovl50_as_AB ((D_8009A1F8_AB_t*)D_800FBC88_ovl50)

extern u8 D_80091C44;

void func_800FA8E0_ovl50(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.tAB.unk3 = 0;
        D_8009A1F8.tAB.unk57 = 0;
        D_800FBC88_ovl50_as_AB->unk36 = 0x22;
        D_8009A1F8.tAB.unkB0 = 0;
        D_8009A1F8.tAB.unkB4 = 0x1000000;
        D_8009A1F8.tAB.unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
    }
}
