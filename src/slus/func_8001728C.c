/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80017A48.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:clear_vram_rect_ptrs, AGPL-3.0; proven shared with X6 by exact signature fd1585f50292 (see THIRD_PARTY.md). */
#include "types.h"
extern RectPtrPair D_800C69B0[];
extern RectPtrPair* D_8009A788;

void func_8001728C(void) {
    u32 i;
    RectPtrPair* ptr;

    ptr = &D_800C69B0[0];
    D_8009A788 = ptr;

    for (i = 0; i < 8; i++) {
        ptr->rect.unk0 = 0;
        ptr->rect.unk2 = 0;
        ptr->rect.unk4 = 0;
        ptr->rect.unk6 = 0;
        ptr->ptr = 0;
        ptr++;
    }
}
