/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800184F4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800163EC, AGPL-3.0; proven shared with X6 by exact signature 65b2d7edf418 (see THIRD_PARTY.md). */
#include "types.h"
void func_80017B5C(u8);
extern s8 D_800D1599;
extern u8 D_800E805C;

void func_80017B2C(void) {
    D_800D1599 = 1;
    func_80017B5C(D_800E805C);
}
