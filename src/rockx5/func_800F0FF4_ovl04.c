#include "types.h"

#define G (*(u8**)0x1F80004C)

extern s32 func_8002FB58(ObjFA284*);
extern u8 D_80101490_ovl04[][4];
extern u8 D_80101498_ovl04[];

s32 func_800F0FF4_ovl04(ObjFA284* o, u8 i) {
    func_8002FB58(o);
    if (o->flags70 & D_80101490_ovl04[G[0x80]][i]) {
        return ((o->flags70 & D_80101498_ovl04[i]) != 0) * 2;
    }
    return 1;
}
