/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80026128.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/144A4.c:func_800241E8, AGPL-3.0; proven shared with X6 by exact signature df4775baa321 (see THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define NULL ((void*)0)
#define SP(offset) (0x1F800000 + (offset))
extern X4_P_TAG* D_80091C50[2][4][8];
extern X4_P_TAG* D_80093E70[2][4][8];

void func_800272FC(void) {
    u32 buffer;
    u32 i;
    u32 j;

    buffer = D_1F800000;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80093E70[buffer][i][j] = NULL;
            D_80091C50[buffer][i][j] = (X4_P_TAG*)&D_80093E70[buffer][i][j];
        }
    }
}
