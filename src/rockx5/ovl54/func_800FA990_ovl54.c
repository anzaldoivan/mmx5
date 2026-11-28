#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FA990_ovl54(Unk800FAD8C* arg0) {
    u16 t;

    if (D_80091C44 == 0) {
        arg0->unk6 += 1;
        t = arg0->unk6;
        if (!(t & 3)) {
            if (D_800D50DE != 0x1F) {
                D_800D50DE++;
                D_8009A42E += 0x20;
                D_80093E68 += 0x400;
            }
        }
        if (++arg0->unk4 > 0x18) {
            arg0->unk1++;
            arg0->unk4 = 0;
        }
    }
}
