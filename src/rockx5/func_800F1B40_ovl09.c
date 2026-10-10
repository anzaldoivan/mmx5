#include "types.h"

extern s32 func_8002FB58(Ent800FE04C*);
extern u8 D_800FAB44_ovl09[][4];
extern u8 D_800FAB4C_ovl09[];

s32 func_800F1B40_ovl09(Ent800FE04C* o, u8 i) {
    func_8002FB58(o);
    if (o->unk70 & D_800FAB44_ovl09[o->pad8F[0]][i]) {
        return ((o->unk70 & D_800FAB4C_ovl09[i]) != 0) * 2;
    }
    return 1;
}
