/* Shared body (DK-5), from the banked draft of func_800F7CB0_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(Ent7CB0*);
extern void func_8002DED4(Ent7CB0*);
extern u8 D_800FA0BC_ovl03[][6];

void DEDUP_NAME(Ent7CB0* e) {
    if (++e->unk7C == 6) {
        u8 t;
        t = D_800FA0BC_ovl03[e->unk92][e->unk93++];
        e->unk6 = 0;
        e->unk5 = t;
    }
    func_80017248(e);
    func_8002DED4(e);
}
