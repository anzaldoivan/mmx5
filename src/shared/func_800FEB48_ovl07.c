/* Shared body (DK-5), from the banked draft of func_800FEB48_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 DEDUP_CALLEE(Ent800FE04C*);
extern u8 D_80101DF0_ovl07[][4];
extern u8 D_80101DF8_ovl07[];

s32 DEDUP_NAME(Ent800FE04C* o, u8 i) {
    DEDUP_CALLEE(o);
    if (o->unk70 & D_80101DF0_ovl07[o->pad71[0x1B]][i]) {
        return ((o->unk70 & D_80101DF8_ovl07[i]) != 0) * 2;
    }
    return 1;
}
