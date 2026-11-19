#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A24C[3];
extern u8* D_800FAC30_ovl46;

void func_800FA7E8_ovl46(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A24C[0].unk3 = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
        D_800FAC30_ovl46[6] = 2;
    }
}
