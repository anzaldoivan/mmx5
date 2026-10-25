/* Shared body (DK-5), from the banked draft of func_800F50BC_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800FD424_ovl27[])(Ent50BC*);
extern u8 D_800FD350_ovl27[];
extern u8 D_80074EE0[];
extern u8 D_800FD34C_ovl27[];
extern u8 D_80075980[];
extern u8 D_800FD344_ovl27[];
extern u8 D_800FD348_ovl27[];
extern u8 D_800FD408_ovl27[];
extern void func_80017248(Ent50BC*);
extern void func_800F5AB4_ovl27(Ent50BC*);
extern s32 func_800317B8(Ent50BC*);
extern s32 func_80031DD0(Ent50BC*);
extern void func_80054440(Ent50BC*, s32);
extern void func_8004D4F4(s32, void*, Ent50BC*);
extern s32 func_8002D938(Ent50BC*, s32, s32);
extern void func_8002D9EC(Ent50BC*, s32, s32);

// from rockx5 800F50BC: per-frame update, runs the state handler then probes the floor/contact checks
void DEDUP_NAME(Ent50BC* e) {
    D_1F80004C.scr5308->unk89 = e->unk5;
    if (D_8009A197 == 0) {
        e->unk18 = e->unk8;
        e->unk1C = e->unkC;
        func_80017248(e);
        func_800F5AB4_ovl27(e);
        D_800FD424_ovl27[e->unk5](e);
    }
    if (D_1F80004C.scr5308->unk88 != 0) {
        e->unk50 = D_800FD350_ovl27;
        func_800317B8(e);
        e->unk58 = D_80074EE0;
        e->unk54 = D_800FD34C_ovl27;
        if (func_80031DD0(e) == 0) {
            e->unk58 = D_80075980;
            e->unk54 = D_800FD344_ovl27;
            if (func_80031DD0(e) < 0) {
                func_80054440(e, 0x12);
                func_8004D4F4(5, D_800FD408_ovl27, e);
                e->unk3 = 0;
                e->unk7C = 0x1E;
                e->unk7E = 5;
                e->unk4 = 4;
                return;
            }
        }
    } else {
        e->unk50 = D_800FD348_ovl27;
        func_800317B8(e);
        e->unk58 = D_80075980;
        e->unk54 = D_800FD344_ovl27;
        if (func_80031DD0(e) < 0) {
            func_80054440(e, 0x12);
            func_8004D4F4(5, D_800FD408_ovl27, e);
            e->unk3 = 0;
            e->unk7C = 0x1E;
            e->unk7E = 5;
            e->unk4 = 4;
            return;
        }
    }
    if (func_8002D938(e, 0x40, 0x40) == 0) {
        func_8002D9EC(e, 0x20, 0x20);
    } else {
        e->unk4 = 3;
    }
}
