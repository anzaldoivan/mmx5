/* Shared body (DK-5), from the banked draft of func_800F7724_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002DF54(Ent7724*);
extern void func_80017248(Ent7724*);
extern void func_800171E8(Ent7724*, s32);
extern s32 func_8002DF78(void);
extern s16 D_8009A0AA;

void DEDUP_NAME(Ent7724* e) {
    u32 r;

    if (e->unkA > D_8009A0AA) {
        e->unk15 = 0;
    } else {
        e->unk15 = 0x40;
    }
    func_8002DF54(e);
    func_80017248(e);
    if (--e->unk7C == 0) {
        func_800171E8(e, 2);
        e->unk7C = 90;
        r = func_8002DF78();
        e->unk6++;
        e->unk7E = (u8)(r % 3) + 2;
    }
}
