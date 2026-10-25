/* Shared body (DK-5), from the banked draft of func_800F0FF4_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern s32 DEDUP_CALLEE(ObjFA284*);
extern u8 D_80101490_ovl04[][4];
extern u8 D_80101498_ovl04[];

s32 DEDUP_NAME(ObjFA284* o, u8 i) {
    DEDUP_CALLEE(o);
    if (o->flags70 & D_80101490_ovl04[G[0x80]][i]) {
        return ((o->flags70 & D_80101498_ovl04[i]) != 0) * 2;
    }
    return 1;
}
