/* Adapted from mmx6 @c1c892d src/shared/rock_08/func_800E99AC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_init, AGPL-3.0; proven shared with X6 by exact signature 561f8a99cfb3 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_800171E8(void*, s32);

void func_800F1794_ovl07(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    M2C_FIELD(arg0, s16*, 0x54) = 0xFF;
    M2C_FIELD(arg0, s16*, 0x56) = 0xFF;
    arg0->unk16 = 6;
    func_800171E8(arg0, 0x15);
}
