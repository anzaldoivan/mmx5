/* Shared body (DK-5), from the banked draft of func_800FB930_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern s32 DEDUP_CALLEE(s32);
extern u32* D_80098118;
extern u8 D_8009A2F2;

void DEDUP_NAME(Ent3CC* p) {
    s32 a;
    s32 b;

    p->unk0 = 0x41;
    p->unk14 = D_8009A2F2;
    p->unk40 = D_80098118[DEDUP_CALLEE(0x95)] >> 7;
    p->unk3C = (u8*)D_1F800020.u32s + D_1F800020.u32s[DEDUP_CALLEE(0x95)];
    a = DEDUP_CALLEE(0x95);
    b = DEDUP_CALLEE(0x95);
    p->unk42 = ((a * 4 + 0x18) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
    p->unk16 = 0x20;
    p->unk47 = 0;
    p->pad3 = 0;
    p->unk15 = 0;
    p->x.h.hi = 0x1A0;
    p->y.h.hi = 0x30;
    p->unk20 = -0x1000;
    p->unk24 = 0;
    p->unk4++;
}
