#include "types.h"

extern s32 func_8002FB58(Ent800FE04C*);
extern u8 D_80101DF0_ovl07[][4];
extern u8 D_80101DF8_ovl07[];

s32 func_800FEB48_ovl07(Ent800FE04C* o, u8 i) {
    func_8002FB58(o);
    if (o->unk70 & D_80101DF0_ovl07[o->pad71[0x1B]][i]) {
        return ((o->unk70 & D_80101DF8_ovl07[i]) != 0) * 2;
    }
    return 1;
}
