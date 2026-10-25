/* Adapted from mmx6 @c1c892d src/shared/rock_06/func_800F26E4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mech.c:func_8003F648, AGPL-3.0; proven shared with X6 by exact signature 020323399ced (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern void (*D_800FDE9C_ovl06[])(X4_Obj*);

void func_800F2CEC_ovl06(X4_Obj* arg0) {
    if (!(M2C_FIELD(arg0, s8*, 0x97) & 2)) {
        D_800FDE9C_ovl06[arg0->unk6](arg0);
    }
}
