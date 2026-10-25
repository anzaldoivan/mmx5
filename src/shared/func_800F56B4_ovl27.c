/* Shared body (DK-5), from the banked draft of func_800F56B4_ovl27 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(Obj3DD4*, s32);
extern s32 func_8002DF78(void);

void DEDUP_NAME(Obj3DD4* o) {
    u32 r;

    func_800171E8(o, 2);
    D_1F80004C.bytes[0x88] = 1;
    r = func_8002DF78();
    o->unk6++;
    o->unk7C = (u8)(r % 120) + 60;
}
