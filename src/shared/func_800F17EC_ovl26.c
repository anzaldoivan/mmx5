/* Shared body (DK-5), from the banked draft of func_800F17EC_ovl26 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(Obj17EC*);
extern void func_800171E8(Obj17EC*, s32);
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj17EC* arg0) {
    s32 d;

    func_8002DF54(arg0);
    if ((((d = D_8009A0AA - arg0->unkA) >= 0)
             ? (d < 5)
             : ((arg0->unkA - D_8009A0AA) < 5)) ||
        !((((d = *(s16*)(D_1F80004C.bytes + 0x82) - arg0->unkA) >= 0)
               ? (d < 0xA0)
               : ((arg0->unkA - *(s16*)(D_1F80004C.bytes + 0x82)) < 0xA0)))) {
        func_800171E8(arg0, 2);
        arg0->unk54 = 0;
        arg0->unk50 = 0;
        arg0->unk7C = 0;
        arg0->unk6++;
    }
}
