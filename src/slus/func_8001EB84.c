/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001D760.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D57C, AGPL-3.0; proven shared with X6 by exact signature 57aab085cb3c (see THIRD_PARTY.md). */
#include "types.h"
void func_80022618(void);
#define M2C_UNK s32
extern void (*D_80070ED4[])(struct X4_GameInfo* arg0);
void func_80024698(void);

void func_8001EB84(struct X4_GameInfo* arg0) {
    D_80070ED4[arg0->mode](arg0);
    func_80022618();
    func_80024698();
}
