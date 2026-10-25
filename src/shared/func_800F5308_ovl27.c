/* Shared body (DK-5), from the banked draft of func_800F5308_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A0B4;
extern u8 D_800FD3D8_ovl27[];
extern u8 D_80075980[];
extern u8 D_800FD344_ovl27[];
extern u8 D_800FD348_ovl27[];
extern void func_800171E8(Ent5308*, s32);
extern void func_800F5C58_ovl27(Ent5308*);

// from rockx5 800F5308: init routine, seeds anim/state pointers and resets the scratch block
void DEDUP_NAME(Ent5308* e) {
    e->unk5C = 0x20;
    e->unk60 = 0xA;
    e->unk61 = 0;
    e->unk14 = D_8009A0B4;
    e->unk67 = 0;
    e->unk30 = D_800FD3D8_ovl27;
    e->unk16 = 6;
    e->unk58 = D_80075980;
    e->unk54 = D_800FD344_ovl27;
    e->unk50 = D_800FD348_ovl27;
    e->unk68 = 0;
    e->unk20 = 0;
    e->unk28 = 0;
    e->unk24 = 0;
    e->unk2C = 0;
    e->unk3 = 1;
    e->unk18 = e->unk8;
    e->unk1C = e->unkC;
    func_800171E8(e, 0);
    func_800F5C58_ovl27(e);
    D_1F80004C.scr5308->unk86 = 0;
    D_1F80004C.scr5308->unk87 = 0;
    D_1F80004C.scr5308->unk88 = 0;
    D_1F80004C.scr5308->unk80 = e->unkC;
    D_1F80004C.scr5308->unk84 = 0;
    e->unk4 = 1;
    e->unk5 = 2;
    e->unk6 = 0;
    D_1F80004C.scr5308->unk89 = 2;
}
