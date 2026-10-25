/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D8EC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D698, AGPL-3.0; proven shared with X6 by exact signature 08f62733c4aa (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001ED08(struct X4_GameInfo* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 0x0) = 0;
    arg0->mode = 0;
    M2C_FIELD(arg0, s8*, 0x2) = 0;
    M2C_FIELD(arg0, s8*, 0x3) = 0;
    if (++M2C_FIELD(arg0, s8*, 0xC) == 4) {
        M2C_FIELD(arg0, s8*, 0xC) = 0;
    }
}
