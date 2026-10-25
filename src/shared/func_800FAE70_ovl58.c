/* Shared body (DK-5), from the banked draft of func_800FAE70_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern s32 D_800E92F8;

void DEDUP_NAME(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 >= 61) {
        D_8009A1F8.pad0[3] = 0;
        D_8009A1F8.unk57 = 0;
        *(s16*)&D_8009A1F8.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.unkB6 = 0x400;
        D_8009A1F8.unkF4 = 1;
        D_800E92F8 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
