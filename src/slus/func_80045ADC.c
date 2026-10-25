/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EE14C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_22_nova_strike_hitbox.c:nova_strike_hitbox_update, AGPL-3.0; proven shared with X6 by exact signature ab318e028ab5 (see THIRD_PARTY.md). */
#include "types.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_8009A0A0;
#define D_8009A0A0 (*(X4_Obj*)&D_8009A0A0)
extern Unk800770CC D_80076E50[];
M2C_UNK func_8002D6FC();
#define func_8002D6FC ((void (*)(X4_Obj * arg0)) func_8002D6FC)

void func_80045ADC(X4_Obj* arg0) {
    X4_Obj* player = &D_8009A0A0;
    u8 temp_v0;

    if (D_8009A0A0.unk5 != 0x23) {
        func_8002D6FC(arg0);
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
#undef D_8009A0A0
#undef func_8002D6FC
