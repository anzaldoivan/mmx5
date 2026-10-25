/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001B784.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80018EEC, AGPL-3.0; proven shared with X6 by exact signature e997ebfce7dc (see THIRD_PARTY.md). */
#include "types.h"
extern s32 D_800E8118;
extern s32 D_800E811C;
extern volatile s32 D_800E8174;

void func_8001B0E8(void) {
    do {

    } while (D_800E8174 != 0);
    D_800E8118 = D_800E811C;
}
