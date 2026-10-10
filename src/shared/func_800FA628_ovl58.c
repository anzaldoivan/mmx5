/* Shared body (DK-5), from the banked draft of func_800FA628_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void DEDUP_NAME(UnkObj* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        *(s16*)(p + 0x5E) = 0x200;
        *(s16*)(p + 0x62) = 0;
        p[0xA0] = 1;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
