/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EE14C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_22_nova_strike_hitbox.c:nova_strike_hitbox_update, AGPL-3.0; proven shared with X6 by exact signature ab318e028ab5 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)
extern Unk800770CC D_80076E50[];
#define clear_object_slot ((void (*)(X4_Obj * arg0)) clear_object_slot)

void func_80045ADC(X4_Obj* arg0) {
    X4_Obj* player = &g_Player_as_X4_Obj;
    u8 temp_v0;

    if (g_Player_as_X4_Obj.unk5 != 0x23) {
        clear_object_slot(arg0);
        return;
    }
    if (arg0->state == 0) {
        arg0->unk50 = &D_80076E50;
        arg0->unk64 = 1U;
        M2C_FIELD(arg0, u8*, 0x8C) = 4U;
        arg0->state++;
    } else {
        temp_v0 = M2C_FIELD(arg0, u8*, 0x8C);
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, u8*, 0x8C) = 4U;
            arg0->unk64++;
        } else {
            M2C_FIELD(arg0, u8*, 0x8C) = temp_v0 - 1;
        }
    }
    arg0->x_pos.val = player->x_pos.val;
    arg0->y_pos.val = player->y_pos.val;
    arg0->unk15 = player->unk15;
}
#undef g_Player_as_X4_Obj
#undef clear_object_slot
