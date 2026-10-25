/* Shared body (DK-5), from the banked draft of func_800F8084_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj8084*, s32);
extern void func_80017248(Obj8084*);
extern void func_8002DED4(Obj8084*);
extern u8 D_800F9E6C_ovl03[];
extern u8 D_8009A197;
extern u8 D_800D1C10;
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(Obj8084* e) {
    s16 t;

    t = ++e->unk7C;
    if (t == 100) {
        e->unk54 = D_800F9E6C_ovl03;
        D_8009A197 = 0;
        D_800D1C10 = 0;
    } else if (t == 180) {
        u8 v;
        func_800171E8(e, 1);
        v = D_800FA0BC_ovl03[e->unk92][e->unk93++];
        e->unk6 = 0;
        e->unk5 = v;
    }
    func_80017248(e);
    func_8002DED4(e);
}
