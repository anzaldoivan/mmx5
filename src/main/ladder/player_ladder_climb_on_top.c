/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037548.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_ladder_climb_on_top, AGPL-3.0; proven shared with X6 by exact signature 78487e2d128b (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
extern int func_8003B148();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define M2C_UNK s32
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);

M2C_UNK func_8003CD08();
void player_ladder_climb_on_top(X4_BackgroundObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (self->unk45 & 0x80) {
        self->unk45 = 0;
        self->y_pos.i.hi = (self->y_pos.u.hi & 0xFFF0) + 0x20;
    }
    if (M2C_FIELD(self, s8*, 0x46) < 0) {
        self->y_pos.i.hi = self->y_pos.u.hi + 0x10;
        ((void (*)())func_8003CD08)(self);
        player_set_animation_frame(self, 0x20, 3);
        func_8003B148(self);
    }
}
