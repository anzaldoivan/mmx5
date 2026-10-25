/* Shared body (DK-5), from the banked draft of func_8002A4E4 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002935C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027D40, AGPL-3.0; proven shared with X6 by exact signature 6ee72b467391 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s8 D_8009A16C;
extern X4_BackgroundObj D_8009A24C[3];
extern void (*D_800718E8[])(X4_BackgroundObj*);

void DEDUP_NAME(void) {
    X4_BackgroundObj* ptr = D_8009A24C;
    if (M2C_FIELD(ptr, s8*, 0x44) != 0 && D_8009A16C == 0) {
        ptr->unk14.val = ptr->x_pos.val;
        ptr->unk18.val = ptr->y_pos.val;
        D_800718E8[M2C_FIELD(ptr, s8*, 0x4)](ptr);
    }
}
