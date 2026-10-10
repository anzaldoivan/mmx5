/* Shared body (DK-5), from the banked draft of func_800FA844_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void DEDUP_NAME(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0x3] = 1;
        *(s16*)(D_8009A1F8 + 0xA) = 0;
        *(s16*)(D_8009A1F8 + 0xE) = 0;
        D_8009A1F8[0x4C] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
