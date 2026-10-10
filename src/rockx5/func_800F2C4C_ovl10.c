#include "types.h"

extern s32 func_8002FB58(Ent800FE04C*);
extern u8 D_800FB76C_ovl10[][4];
extern u8 D_800FB774_ovl10[];

s32 func_800F2C4C_ovl10(Ent800FE04C* o, u8 i) {
    func_8002FB58(o);
    if (o->unk70 & D_800FB76C_ovl10[o->pad8F[1]][i]) {
        return ((o->unk70 & D_800FB774_ovl10[i]) != 0) * 2;
    }
    return 1;
}
