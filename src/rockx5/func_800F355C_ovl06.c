/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004686C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_61_ride_armor_punch.c:ride_armor_punch_init, AGPL-3.0; proven shared with X6 by exact signature ef5dce611697 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define NULL ((void*)0)
void func_800F341C_ovl06(X4_Obj*);

void func_800F355C_ovl06(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 0;
    arg0->bg_offset = 0;
    arg0->unk68 = NULL;
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk64 = 1;
    arg0->hp = 1;
    arg0->unk60 = 3;
    M2C_FIELD(arg0, u16*, 0x88) = 6;
    func_800F341C_ovl06(arg0);
}
