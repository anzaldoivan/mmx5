#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004B4BC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_22_missile_smoke.c:missile_smoke_init, AGPL-3.0; proven shared with X6 by exact signature 350f949ca2ac (see THIRD_PARTY.md). */
void func_800F3658_ovl06(X4_Obj*);

void func_800F3608_ovl06(X4_Obj* arg0) {
    arg0->state = 1;
    arg0->on_screen = 1;
    if (arg0->unk2 != 0x10) {
        arg0->unk15 = 0;
        func_800F3658_ovl06(arg0);
    } else {
        arg0->unk16 = 2;
        set_animation(arg0, 0x25);
    }
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004B50C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_22_missile_smoke.c:missile_smoke_main, AGPL-3.0; proven shared with X6 by exact signature c82f771f5c19 (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3658_ovl06(X4_Obj* arg0) {
    X4_Obj* temp_a0;

    if (arg0->unk2 != 0x10) {
        if (arg0->unk2 <= 6) {
            if (arg0->unk2 == 0) {
                set_animation(arg0, 0x21);
            } else {
                set_animation(arg0, ((arg0->unk2 - 1) >> 1) + 0x21);
            }
            arg0->unk2++;
            ((s32(*)())func_8002D89C)(arg0);
        } else {
            arg0->on_screen = 0;
            arg0->state = 2;
        }
    } else {
        temp_a0 = M2C_FIELD(arg0, X4_Obj**, 0x50);
        if (((u8)M2C_FIELD(temp_a0, s8*, 0x94) == 2) &&
            (temp_a0->active != 0) && (M2C_FIELD(temp_a0, s8*, 0x97) & 0x40)) {
            arg0->unk15 = temp_a0->unk15;
            arg0->x_pos.i.hi = temp_a0->x_pos.i.hi;
            arg0->y_pos.i.hi = temp_a0->y_pos.i.hi;
            ((void (*)())animate_object)(arg0);
            ((s32(*)())func_8002D89C)(arg0);
            return;
        }
        arg0->on_screen = 0;
        ((void (*)())clear_object_slot)(arg0);
    }
}
