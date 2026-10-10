/* Shared body (DK-5), from the banked draft of func_800F57B4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(Obj3DD4*, s32);
extern s32 func_8002DF78(void);

void DEDUP_NAME(Obj3DD4* o) {
    u32 r;

    func_800171E8(o, 3);
    o->unk7C = 1;
    r = func_8002DF78();
    o->unk6++;
    o->unk7E = (u8)(r % 3) + 2;
}
