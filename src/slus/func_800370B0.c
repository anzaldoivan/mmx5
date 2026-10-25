/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800375D0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_ladder_step_off_bottom, AGPL-3.0; proven shared with X6 by exact signature 26cbae375ca4 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

#define M2C_UNK s32
M2C_UNK func_80017248();
M2C_UNK func_8003A70C(void*);
void func_800370B0(ObjEE5C* self) {
    ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
    if (self->unk46 < 0) {
        M2C_FIELD(self, s8*, 0x67) = 0;
        ((void (*)())func_8003A70C)(self);
    }
}
