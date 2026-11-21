#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern u8 D_80101490_ovl04[][4];
extern u8 D_80101498_ovl04[];

s32 func_800F0FF4_ovl04(ObjFA284* o, u8 i) {
    func_8002FB58(o);
    if (o->flags70 & D_80101490_ovl04[G[0x80]][i]) {
        return ((o->flags70 & D_80101498_ovl04[i]) != 0) * 2;
    }
    return 1;
}
