/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037548.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_ladder_climb_on_top, AGPL-3.0; proven shared with X6 by exact signature 78487e2d128b (see THIRD_PARTY.md). */
#include "types.h"
extern int func_8003B148();
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define M2C_UNK s32
M2C_UNK func_8003B4CC(void*, M2C_UNK, s8);

M2C_UNK func_80017248();
M2C_UNK func_8003CD08();
void func_80037028(X4_BackgroundObj* self) {
    ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
    if (self->unk45 & 0x80) {
        self->unk45 = 0;
        self->y_pos.i.hi = (self->y_pos.u.hi & 0xFFF0) + 0x20;
    }
    if (M2C_FIELD(self, s8*, 0x46) < 0) {
        self->y_pos.i.hi = self->y_pos.u.hi + 0x10;
        ((void (*)())func_8003CD08)(self);
        func_8003B4CC(self, 0x20, 3);
        func_8003B148(self);
    }
}
