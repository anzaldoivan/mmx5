/* Shared body (DK-5), from the banked draft of func_800F01A8_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A0B4;
extern u8 D_800FD98C_ovl28[];
extern u8 D_800FD9C8_ovl28[];
extern u8 D_800FD9C0_ovl28[];
extern u8 D_800750C0[];
extern s32 func_8002DF78(void);
extern void func_800171E8(Ent01A8*, s32);

void DEDUP_NAME(Ent01A8* e) {
    s32 t = D_8009A0B4;
    s32 r;

    e->unk30 = D_800FD98C_ovl28;
    e->unk16 = 4;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk68 = 0;
    e->unk50 = D_800FD9C8_ovl28;
    e->unk54 = D_800FD9C0_ovl28;
    e->unk58 = D_800750C0;
    e->unk61 = 0;
    e->unk5C = 5;
    e->unk60 = 3;
    e->unk4 = 1;
    e->unk6 = 0;
    e->unk14 = t;
    r = func_8002DF78() & 3;
    t = (s32)D_1F80004C.scr01a8;
    ((Scr01A8*)t)->unk81 = r;
    D_1F80004C.scr01a8->unk89 = 0;
    if (e->unk2 & 0x80) {
        func_800171E8(e, 0);
        e->unk5 = 2;
        e->unk67 = 1;
    } else {
        e->unk15 = 0;
        func_800171E8(e, 0);
        e->unk67 = 0;
        e->unk5 = 3;
    }
    if ((e->unk2 & 0xF) == 1) {
        e->unk4 = 3;
    }
    if (e->unk2 == 3) {
        func_800171E8(e, 1);
        D_1F80004C.scr01a8->unk8A = e->unk6;
        D_1F80004C.scr01a8->unk8B = e->unk7C;
        D_1F80004C.scr01a8->unk8E = e->unkE;
        D_1F80004C.scr01a8->unk90 = e->unk24;
        D_1F80004C.scr01a8->unk94 = e->unk2C;
        e->unk5 = 7;
    }
}
