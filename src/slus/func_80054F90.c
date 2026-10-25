/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80051104.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/items/item_08_boss_door.c:boss_door_block_player, AGPL-3.0; proven shared with X6 by exact signature 37a985cf43c2 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern X4_Obj D_8009A0A0;

void func_80054F90(X4_Obj* arg0) {
    volatile X4_Obj* player = &D_8009A0A0;

    if (M2C_FIELD(arg0, s8*, 0x72) & 4) {
        player->unk71 = (u8)(player->unk71 & 0xB);
    }
    if (M2C_FIELD(arg0, s8*, 0x72) & 8) {
        player->unk71 = (u8)(player->unk71 & 7);
    }
}
