/* Shared body (DK-5), from the banked draft of func_800F27DC_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#define g_Player_as_Obj66A0 (*(Obj66A0*)&g_Player)

void DEDUP_NAME(Obj66A0* e) {
    s32 d;

    d = g_Player_as_Obj66A0.unkE - e->unkE;
    if (d >= 0 ? d >= 4 : e->unkE - g_Player_as_Obj66A0.unkE >= 4) {
        if (g_Player_as_Obj66A0.unkE >= e->unkE) {
            e->unk24 = -0x10000;
        } else {
            e->unk24 = 0x10000;
        }
    } else {
        e->unk24 = 0;
    }
    DEDUP_CALLEE(e);
    if (--e->unk7C == -1) {
        e->unk5 = 3;
        e->pad6[0] = 0;
    }
}
