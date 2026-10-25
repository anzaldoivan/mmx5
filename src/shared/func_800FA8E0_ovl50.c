/* Shared body (DK-5), from the banked draft of func_800FA8E0_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_AB_t D_8009A1F8;
extern D_8009A1F8_AB_t* D_800FBC88_ovl50;

void DEDUP_NAME(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.unk3 = 0;
        D_8009A1F8.unk57 = 0;
        D_800FBC88_ovl50->unk36 = 0x22;
        D_8009A1F8.unkB0 = 0;
        D_8009A1F8.unkB4 = 0x1000000;
        D_8009A1F8.unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk1++;
    }
}
