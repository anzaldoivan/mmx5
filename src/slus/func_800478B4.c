/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801F0814.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_02_frost_tower.c:frost_tower_despawn, AGPL-3.0; proven shared with X6 by exact signature d5fdc58f219e (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_800478B4(X4_Obj* arg0) {
    arg0->unk50 = 0;
    arg0->unk68 = 0;
    g_Player[0x98]--;
    g_Player[0x99]--;
    clear_object_slot(arg0);
}
