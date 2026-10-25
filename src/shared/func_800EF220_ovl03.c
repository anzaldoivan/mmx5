/* Shared body (DK-5), from the banked draft of func_800EF220_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_800F9660_ovl03[])(ObjEF094*);
extern void* D_800F9658_ovl03[];
extern u8 D_800F9644_ovl03[];
extern s32 func_800317B8(ObjEF094*);
extern s32 func_80031DD0(ObjEF094*);
extern void func_800EFD08_ovl03(ObjEF094*);
extern s32 func_8004FD24(ObjEF094*);
extern void func_8004D4F4(s32, void*, ObjEF094*);
extern void func_80054440(ObjEF094*, s32);
extern s32 func_8002D938(ObjEF094*, s32, s32);
extern void func_8002D9EC(ObjEF094*, s32, s32);

void DEDUP_NAME(ObjEF094* e) {
    u8 hit;
    u8 i;
    s32 r;
    s32 state;

    if (D_8009A197 == 0) {
        e->unk18 = e->unk8;
        e->unk1C = e->unkC;
        D_800F9660_ovl03[e->unk5](e);
    }
    hit = func_800317B8(e);
    if (e->unk2 == 4 && hit == 1) {
        e->unk5 = 8;
        e->unk6 = 0;
    }
    if (e->unk5 != 0) {
        e->unk94 = e->unk5;
    }
    if (e->unk5 != 9) {
        for (i = 0; i < 2 - e->unk88; i++) {
            e->unk54 = D_800F9658_ovl03[i];
            r = func_80031DD0(e);
            if (r < 0) {
                if (i == 0 && e->unk88 == 0) {
                    func_800EFD08_ovl03(e);
                }
                func_8004FD24(e);
                func_8004D4F4(4, D_800F9644_ovl03, e);
                func_80054440(e, 8);
                state = e->unk4 + 1;
                goto end; // !FAKE: shared store tail with the 0x20 probe below
            }
            if (r != 0) {
                break;
            }
        }
    }
    if (func_8002D938(e, 0x20, 0x20) == 0) {
        if (e->unk5 != 9) {
            func_8002D9EC(e, 0x20, 0x20);
        }
        return;
    }
    state = 3;
end:
    e->unk4 = state;
}
