/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800377FC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_ladder_let_go, AGPL-3.0; proven shared with X6 by exact signature 97ce869b32ad (see THIRD_PARTY.md). */
#include "types.h"
void func_8003A94C(u8* obj);
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

#define M2C_UNK s32
M2C_UNK func_80017248(void*);
void func_800372AC(ObjEE5C* self) {
    ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
    if (self->unk46 < 0) {
        func_8003A94C(self);
    }
}
