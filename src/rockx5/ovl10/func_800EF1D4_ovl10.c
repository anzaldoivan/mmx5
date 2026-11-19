/* Adapted from mmx6 @c1c892d src/shared/rock_09/func_800E9A60.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_07_water_wake.c:water_wake_main, AGPL-3.0; proven shared with X6 by exact signature b82c7ed308c9 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#define FIXED(x) ((s32)((x) * 0x10000))
extern void (*D_800FAC70_ovl10[])(X4_Obj*, X4_Obj*);
u8 get_tile_attr_bottom(X4_Obj*);

void func_800EF1D4_ovl10(X4_Obj* arg0, X4_Obj* arg1) {
    if (arg1->hp == 0 || arg1->state == 3) {
        clear_object_slot(arg0);
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
    if (get_tile_attr_bottom(arg1) != 0x24) {
        arg0->on_screen = 0;
    }
    if (arg0->on_screen != 0) {
        func_8002D89C(arg0);
    }
}
