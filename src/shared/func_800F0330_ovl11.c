/* Shared body (DK-5), from the banked draft of func_800F0330_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl11.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern u8 D_800D1C00[];
extern u8 D_800F9730_ovl11[];
extern s32 func_8002E804(u8*, u8*);

void DEDUP_NAME(u8* arg0) {
    u8* p;
    s32 r;

    if ((g_Player[0x5C] & 0x7F) && func_8002E804(arg0, g_Player)) {
        arg0[5] = 0;
        p = D_800D1C00;
        if ((signed char)++p[0x45] >= 10) {
            p[0x45] = 9;
        } else {
            play_sound(0, 0x15, 0);
        }
        r = random_byte() & 3;
        func_800EFFA0_ovl11(arg0, D_800F9730_ovl11[r], r);
    }
}
