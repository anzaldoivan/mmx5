#include "types.h"
extern u8 D_800FAB50_ovl10[9][16];
extern u8 D_800FABE0_ovl10[9][16];

s32 func_800EF450_ovl10(X4_Obj* arg0) {
    u8 state;

    if (arg0->unk2 == 0) {
        state = D_800FAB50_ovl10[0][arg0->unk17];
    } else {
        state = D_800FABE0_ovl10[0][arg0->unk17];
    }

    return state == 1;
}
