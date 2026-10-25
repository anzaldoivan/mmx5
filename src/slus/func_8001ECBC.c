/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D8A0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D64C, AGPL-3.0; proven shared with X6 by exact signature 370ee8910a36 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_800132F8(s32);

void func_8001ECBC(struct X4_GameInfo* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x4) == 0) {
        arg0->mode++;
        func_800132F8(8);
    }
}
