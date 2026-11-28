#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FAD10_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8_AD10_t* p = &D_8009A1F8.tAD10;

        p->unkAB = 1;
        p->unkB2 = 0;
        p->unkB6 = 0x300;
        p->unkF4 = 1;
        arg0->unk1++;
        arg0->unk6 = 0;
        func_8002385C(0x65, 0xFF, 0);
    }
}
