/* Adapted from mmx6 @c1c892d src/shared/rock_00/func_801EEB7C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/weapons/weapon_20_plasma_shot.c:buster_shot_follow_muzzle, AGPL-3.0; proven shared with X6 by exact signature 06aa2f0ae247 (see THIRD_PARTY.md). */
#include "types.h"
extern int func_80045D44();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define VISUAL_OBJECT(object) ((X4_Obj*)(object))

void func_800464F0(SpawnEEE84* arg0) {
    X4_Obj* owner;

    if (arg0->unk84 == 0) {
        owner = M2C_FIELD(arg0, X4_Obj**, 0x7C);
        if (M2C_FIELD(owner, s8*, 0x8E) == 0) {
            arg0->unk84 = 1;
        }
        if (owner->unk15 != M2C_FIELD(arg0, u8*, 0x15)) {
            arg0->unk84 = 1;
        }
        if (arg0->unk84 == 0) {
            func_80045D44(VISUAL_OBJECT(arg0), owner,
                          M2C_FIELD(arg0, s8*, 0x1));
        }
    }
}
