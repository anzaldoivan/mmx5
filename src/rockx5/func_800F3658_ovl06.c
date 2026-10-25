/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004B50C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_22_missile_smoke.c:missile_smoke_main, AGPL-3.0; proven shared with X6 by exact signature c82f771f5c19 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_800171E8(void*, s32);

#define M2C_UNK s32
M2C_UNK func_80017248();
M2C_UNK func_8002D6FC(void*, void*);
s32 func_8002D89C(X4_Obj*);
void func_800F3658_ovl06(X4_Obj* arg0) {
    X4_Obj* temp_a0;

    if (arg0->unk2 != 0x10) {
        if (arg0->unk2 <= 6) {
            if (arg0->unk2 == 0) {
                func_800171E8(arg0, 0x21);
            } else {
                func_800171E8(arg0, ((arg0->unk2 - 1) >> 1) + 0x21);
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
            ((void (*)())func_80017248)(arg0);
            ((s32(*)())func_8002D89C)(arg0);
            return;
        }
        arg0->on_screen = 0;
        ((void (*)())func_8002D6FC)(arg0);
    }
}
