/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F70.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_script_vanish, AGPL-3.0; proven shared with X6 by exact signature 8c272e77d29e (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
s32 func_80039ECC(u8* arg0);
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

#define M2C_UNK s32
M2C_UNK func_80017248(void*);
void func_80037B88(X4_Obj* self) {
    if (func_80039ECC(self) == 0 && self->unk6 == 0) {
        ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
        if (M2C_FIELD(self, s8*, 0x46) == 0) {
            self->on_screen = 0;
            self->unk6++;
        }
    }
}
