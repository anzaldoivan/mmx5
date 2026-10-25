/* Shared body (DK-5), from the banked draft of func_800F0028_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_8002DF54(Obj4FE0*);
extern void func_800171E8(Obj4FE0*, s32);
extern s32 func_8002DF78(void);
extern s16 D_8009A0AA;

void DEDUP_NAME(Obj4FE0* e) {
    s32 d;

    func_8002DF54(e);
    d = D_8009A0AA - e->unkA;
    if (d >= 0 ? d < 0x20 : e->unkA - D_8009A0AA < 0x20) {
        func_800171E8(e, 2);
        e->unk6++;
        D_1F80004C.scr->unk86 = (func_8002DF78() & 7) + 1;
    }
}
