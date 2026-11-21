#include "types.h"
#include "mmx5/system.h"

extern u8 D_80091C44;
extern s16 D_8009A2AE;

void func_800FA990_ovl50(Unk800FAD8C* arg0) {
    if (++arg0->unk6 & 1) {
        D_8009A2AE = (random_byte() % 5) + 0x104;
    } else {
        D_8009A2AE = 0x100;
    }
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
