/* Shared body (DK-5), from the banked draft of func_800FAF38_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj1334* DEDUP_CALLEE();
extern u8 D_800FF470_ovl06[];

void DEDUP_NAME(Obj1334* parent, s16 x, s16 y, u8 kind) {
    Obj1334* child;

    child = DEDUP_CALLEE();
    if (child != 0) {
        child->unk0 = 0x41;
        child->unk1 = 0x11;
        child->unk7C = parent;
        child->unk2 = kind;
        child->unk15 = parent->unk15;
        child->unkA = x;
        child->unk8 = 0;
        child->unkE = y;
        child->unkC = 0;
        child->unk42 = parent->unk42 & 0x7FFF;
        child->unk30 = D_800FF470_ovl06;
        child->unk3C = parent->unk3C;
        child->unk40 = parent->unk40;
        child->unk14 = parent->unk14;
    }
}
