/* Shared body (DK-5), from the banked draft of func_800FA858_ovl50 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(s32, s32, s32);
extern u8 D_8009A1F8[];

void DEDUP_NAME(Ovl45State* arg0) {
    D_8009A1F8[0x4C] = 1;
    *(s32*)(D_8009A1F8 + 0xC) += 0xC0000;
    arg0->unk4++;
    if (arg0->unk4 >= 10) {
        *(s32*)(D_8009A1F8 + 0xC) = 0xF80000;
        DEDUP_CALLEE(0x2A, 0xFF, 0);
        arg0->unk1++;
    }
}
