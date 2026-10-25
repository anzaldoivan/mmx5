/* Shared body (DK-5), from the banked draft of func_800FAC54_ovl52 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(s32);
extern s32 D_800FB964_ovl52;
extern u8 D_8009A1F8[];

void DEDUP_NAME(UnkObj* arg0) {
    s32 s;
    s32 v;
    u8* p;

    s = DEDUP_CALLEE(D_800FB964_ovl52);
    D_800FB964_ovl52 = (D_800FB964_ovl52 + 0x10) & 0xFFF;
    v = s << 4;
    if (v != 0) {
        v = s << 8;
    }
    p = D_8009A1F8;
    *(s32*)(p + 0xB4) = 0x2000000 - v;
    p[0xF4] = 1;
    arg0->unk4++;
    if (arg0->unk4 >= 90) {
        arg0->unk1++;
    }
}
