/* Shared body (DK-5), from the banked draft of func_800EF2C8_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define SCR D_1F80004C.scr85
extern s8 D_800F4EC0_ovl05[][32];
extern s8 func_8002E024(Ent2*, u8*);

void DEDUP_NAME(Ent2* e) {
    if (SCR->unk85 != 0) {
        SCR->unk85--;
        return;
    }
    SCR->unk86 = func_8002E024(e, g_Player);
    set_animation(e, D_800F4EC0_ovl05[e->unk2][SCR->unk86]);
}
