/* Shared body (DK-5), from the banked draft of func_800F24D4_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800F4770_ovl02[])(ObjEECF8*);
extern void func_80017248(ObjEECF8*);
extern s32 func_80031DD0(ObjEECF8*);
extern s32 func_8002D938(ObjEECF8*, s32, s32);
extern void func_8002D9EC(ObjEECF8*, s32, s32);
extern s32 func_8004FC64(ObjEECF8*);
extern s32 func_8002FB58(ObjEECF8*);

void DEDUP_NAME(ObjEECF8* e) {
    if (D_8009A197 == 0) {
        e->unk18 = e->x.val;
        e->unk1C = e->y.val;
        D_800F4770_ovl02[e->unk5](e);
        func_80017248(e);
    }
    if (func_80031DD0(e) < 0 || D_1F80004C.scr24d4->unk88 <= 0) {
        func_8004FC64(e);
        e->unk4 = 6;
        return;
    }
    if (func_8002D938(e, 0x40, 0x40)) {
        e->unk4 = 6;
        return;
    }
    func_8002D9EC(e, 0x20, 0x20);
    if ((e->unk70 & 0xC) == 0xC || (e->unk70 & 3) == 3) {
        func_8004FC64(e);
        e->unk4 = 6;
        return;
    }
    func_8002FB58(e);
}
