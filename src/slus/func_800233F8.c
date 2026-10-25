/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002132C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/afterimage.c:func_800AE88C, AGPL-3.0; proven shared with X6 by exact signature fb1027ecedab (see THIRD_PARTY.md). */
#include "types.h"

extern void (*D_800712E8[])(X4_Obj*, X4_Obj*);

void func_800233F8(X4_Obj* arg0, X4_Obj* arg1) {
    if (arg1->afterimage == 0) {
        arg0->on_screen = 0;
        arg0->state = 0;
        return;
    }

    D_800712E8[arg0->unk5](arg0, arg1);
}
