/* Shared body (DK-5), from the banked draft of func_800FA2FC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern Ent7C D_8009A0A0;
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_8002DF54(Ent7C*);
extern void func_800FC9E0_ovl07(Ent7C*);

void DEDUP_NAME(Ent7C* e) {
    s32 dx;
    s32 dy;
    s32 ang;
    s32 pad[2];

    if (--e->unk7C == -1) {
        e->unk7C = 0x14;
        e->unk20 = 0;
        e->unk28 = 0;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk6++;
        return;
    }
    dx = D_8009A0A0.unkA - e->unkA;
    dy = D_8009A0A0.unkE - e->unkE;
    if ((dx < 0 ? -dx : dx) < 5 && (dy < 0 ? -dy : dy) < 5) {
        return;
    }
    ang = ratan2(-dy, dx);
    switch (D_1F80004C.bytes[0x8B]) {
    case 0:
        e->unk20 = rcos(ang) << 5;
        e->unk24 = rsin(ang) << 5;
        break;
    case 1: {
        s32 c = rcos(ang);
        s32 lo = c << 4;
        e->unk20 = ((c << 6) + lo) >> 1;
    }
        e->unk24 = rsin(ang) << 5;
        break;
    case 2: {
        s32 c = rcos(ang);
        s32 lo = c << 4;
        e->unk20 = (c << 5) + lo;
    }
        e->unk24 = rsin(ang) << 5;
        break;
    }
    func_8002DF54(e);
    if (e->unk7C & 7) {
        func_800FC9E0_ovl07(e);
    }
}
