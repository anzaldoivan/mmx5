/* Shared body (DK-5), from the banked draft of func_800EEBEC_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern u8 D_8009A0A0[];
extern u8 D_800F4DE8_ovl05[];
extern u8 D_800F4E38_ovl05[];
extern u8 D_800750C0[];
extern u8 D_800F4E7C_ovl05[][16];
extern u8 D_800F4E3C_ovl05[][16];
extern s8 D_800F4EC0_ovl05[][32];
extern s8 func_8002E024(ObjEEBEC*, u8*);
extern void func_800171E8(ObjEEBEC*, s32);

void DEDUP_NAME(ObjEEBEC* s) {
    u8 t = D_8009A0A0[0x14];

    s->unk30 = D_800F4DE8_ovl05;
    s->unk16 = 3;
    s->unk68 = D_800F4E38_ovl05;
    s->unk58 = D_800750C0;
    s->unk5C = 4;
    s->unk15 = 0;
    s->unk14 = t;
    s->unk50 = D_800F4E7C_ovl05[s->unk2];
    s->unk54 = D_800F4E3C_ovl05[s->unk2];
    s->unk61 = 0;
    s->unk60 = 3;
    G[0x84] = 0;
    G[0x85] = 0;
    if (s->unk2 >= 5) {
        s->unk2 = 0;
    }
    if (s->unk2 == 2) {
        s->unk15 = 0x40;
    } else {
        s->unk15 = 0;
    }
    G[0x86] = func_8002E024(s, D_8009A0A0);
    func_800171E8(s, D_800F4EC0_ovl05[s->unk2][(s8)G[0x86]]);
    s->unk4 = 1;
    s->unk5 = 2;
    s->unk6 = 0;
}
