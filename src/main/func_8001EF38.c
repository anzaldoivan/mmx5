/* Adapted from mmx6 @c1c892d src/shared/rock_18/func_800ED330.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001DAD0, AGPL-3.0; proven shared with X6 by exact signature b05a02ff1ea5 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
void func_8001DAB8(u8* a0);
#define D_800D1C00_as_X4_EngineObj (*(X4_EngineObj*)&g_playthrough_state)

void func_8001EF38(struct X4_GameInfo* arg0) {
    func_8001DAB8(&D_800D1C00_as_X4_EngineObj);
}
