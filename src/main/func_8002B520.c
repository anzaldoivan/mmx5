/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002A3E8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/195B4.c:func_80028F58, AGPL-3.0; proven shared with X6 by exact signature a578409ab919 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#define D_800D1C00_as_X4_EngineObj (*(X4_EngineObj*)&g_playthrough_state)
extern EffectSlot30* D_80072F64[13][2];
void func_8002B070(s16, s16, s16, s16, u8);
void func_8002B61C(EffectSlot30*);

void func_8002B520(void) {
    func_8002B070(D_8009A1F8.bg[0].x_pos.i.hi - 0x30,
                  D_8009A1F8.bg[0].x_pos.i.hi + 0x170,
                  D_8009A1F8.bg[0].y_pos.i.hi - 0x30,
                  D_8009A1F8.bg[0].y_pos.i.hi + 0x120, 0);
    func_8002B61C(D_80072F64[D_800D1C00_as_X4_EngineObj.stage]
                            [D_800D1C00_as_X4_EngineObj.substage]);
}
