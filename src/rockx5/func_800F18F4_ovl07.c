/* Adapted from mmx6 @c1c892d src/shared/rock_08/func_800E9B0C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_15_ride_chaser_flash.c:ride_chaser_flash_init, AGPL-3.0; proven shared with X6 by exact signature 339a3fd19fc8 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_800171E8(void*, s32);

void func_800F18F4_ovl07(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    M2C_FIELD(arg0, s16*, 0x54) = 3;
    arg0->unk16 = 2;
    func_800171E8(arg0, 0x19);
}
