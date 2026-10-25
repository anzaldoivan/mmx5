/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049950.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_02_charge_muzzle_flash.c:charge_muzzle_flash_fade, AGPL-3.0; proven shared with X6 by exact signature eb3a6db008dc (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#define M2C_UNK s32
M2C_UNK func_8002D6FC(void*, void*);
M2C_UNK func_8002D9EC(void*, M2C_UNK, M2C_UNK);
void func_8004F824(X4_Obj* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0 || arg0->hp != 0) {
        ((void (*)())func_8002D6FC)(arg0);
    } else {
        ((void (*)())func_8002D9EC)(arg0, 0x40, 0x20);
    }
}
