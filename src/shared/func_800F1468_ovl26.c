/* Shared body (DK-5), from the banked draft of func_800F1468_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void DEDUP_CALLEE(Ent1468*, s32);
extern Plr1468 D_8009A0A0;
extern u8 D_800750C0[];
extern u8 D_800F95A0_ovl26[];
extern u8 D_800D1C4A;

void DEDUP_NAME(Ent1468* o) {
    Plr1468* plr = &D_8009A0A0;

    o->unk5C = 1;
    o->unk60 = -10;
    o->unk61 = 0;
    o->unk58 = D_800750C0;
    o->unk14 = plr->unk14;
    o->unk18 = o->unk8;
    o->unk1C = o->unkC;
    o->unk30 = D_800F95A0_ovl26;
    o->unk16 = 6;
    o->unk3 = 0;
    o->unk54 = 0;
    o->unk50 = 0;
    o->unk68 = 0;
    if (plr->unk2 == 0) {
        if (plr->unkFC & 0x400) {
            D_1F80004C.scr84->unk85 = 1;
        } else {
            D_1F80004C.scr84->unk85 = 0;
        }
    } else if ((D_800D1C4A & 0x10) || (plr->unkFC & 0x400)) {
        D_1F80004C.scr84->unk85 = 1;
    } else {
        D_1F80004C.scr84->unk85 = 0;
    }
    DEDUP_CALLEE(o, 0);
    o->unk67 = 1;
    o->unk20 = 0;
    o->unk28 = 0;
    o->unk24 = 0;
    o->unk2C = 0;
    D_1F80004C.scr84->unk84 = 0;
    D_1F80004C.scr84->unk86 = 0;
    o->unk4 = 1;
    o->unk5 = 2;
    o->unk6 = 0;
}
