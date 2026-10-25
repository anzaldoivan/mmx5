/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004E654.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/items/item_01_stage_block.c:drop_item, AGPL-3.0; proven shared with X6 by exact signature 806a7421f0d6 (see THIRD_PARTY.md). */
#include "types.h"
void func_8005446C(X4_Obj* arg0, s8 arg1, s16 arg2, s16 arg3);

void func_80054440(X4_Obj* arg0, s8 arg1) {
    func_8005446C(arg0, arg1, arg0->x_pos.i.hi, arg0->y_pos.i.hi);
}
