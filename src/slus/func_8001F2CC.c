/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001DFDC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/E47C.c:func_8001E6BC, AGPL-3.0; proven shared with X6 by exact signature 3affa1eca32f (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s8 D_8009A424;
#define D_8009A424 (*(s8(*)[]) & D_8009A424)
void func_8001E668();

void func_8001F2CC(struct X4_GameInfo* arg0) {
    if (D_8009A424[0] == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 1;
        func_8001E668();
        arg0->mode = 0;
        M2C_FIELD(arg0, s8*, 0x0)++;
    }
}
#undef D_8009A424
