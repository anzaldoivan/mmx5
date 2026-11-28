/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800174D4.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800153D4, AGPL-3.0; proven shared with X6 by exact signature 3313a3f0820f (see THIRD_PARTY.md). */
#include "types.h"
extern void func_80062238(void);
extern void func_80062248(void);

void func_80016D1C(u8 arg0) {
    arg0 ? func_80062248() : func_80062238();
}
