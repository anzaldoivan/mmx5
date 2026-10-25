/* Shared body (DK-5), from the banked draft of func_800FA780_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_AB_t D_8009A1F8;
extern D_8009A1F8_AB_t* D_800FBC88_ovl50;
extern void DEDUP_CALLEE(s32, s32, s32);

void DEDUP_NAME(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.unk8 = 0x80000;
        D_8009A1F8.unkC = 0x800000;
        D_8009A1F8.unk4C = 1;
        D_8009A1F8.unk57 = 0;
        D_8009A1F8.unkB0 = 0;
        D_8009A1F8.unkB4 = 0;
        D_8009A1F8.unkF4 = 1;
        D_8009A1F8.unkAB = 1;
        D_800FBC88_ovl50->unk3 = 1;
        D_800FBC88_ovl50->unk36 = 2;
        arg0->unk4 = 0;
        D_8009A1F8.unk3 = 0;
        DEDUP_CALLEE(0x29, 0xFF, 0);
        arg0->unk1++;
    }
}
