/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800E9A60.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_07_water_wake.c:water_wake_main, AGPL-3.0; proven shared with X6 by exact signature b82c7ed308c9 (see THIRD_PARTY.md). */
#include "types.h"
#define FIXED(x) ((s32)((x) * 0x10000))
#define M2C_UNK s32
extern void (*D_800FAC70_ovl10[])(X4_Obj*, X4_Obj*);
M2C_UNK func_8002D6FC();
M2C_UNK func_8002D89C();
u8 func_80030820(X4_Obj*);

void func_800EF1D4_ovl10(X4_Obj* arg0, X4_Obj* arg1) {
    if (arg1->hp == 0 || arg1->state == 3) {
        func_8002D6FC(arg0);
        return;
    }
    arg0->unk15 = arg1->unk15;
    if (arg0->unk2 & 1) {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(8);
    } else {
        arg0->x_pos.val = arg1->x_pos.val + FIXED(-8);
    }
    arg0->y_pos.val = arg1->y_pos.val;
    D_800FAC70_ovl10[arg0->unk5](arg0, arg1);
    if (arg1->active == 0) {
        arg0->on_screen = 0;
    }
    if (func_80030820(arg1) != 0x24) {
        arg0->on_screen = 0;
    }
    if (arg0->on_screen != 0) {
        func_8002D89C(arg0);
    }
}
