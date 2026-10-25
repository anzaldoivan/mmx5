/* Shared body (DK-5), from the banked draft of func_800FA0E4_ovl40 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A1F8[];
extern void DEDUP_CALLEE(s32);

void DEDUP_NAME(UnkObj* obj) {
    u8* p = D_8009A1F8;

    p[0x3] = 0;
    p[0x57] = 0;
    DEDUP_CALLEE(8);
    obj->unk1++;
}
