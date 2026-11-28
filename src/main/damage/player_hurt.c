/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037838.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_hurt, AGPL-3.0; proven shared with X6 by exact signature 94a81587fc1f (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
extern void (*D_80074744[])(X4_Obj*);

void player_hurt(X4_Obj* self) {
    animate_object(ANIMATED_OBJECT(self));
    D_80074744[M2C_FIELD(self, s8*, 0x63)](self);
}
