/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EC2B0.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_51_fortress_cannon.c:fortress_cannon_volley_wait, AGPL-3.0; proven shared with X6 by exact signature 7c2510b02378 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

void func_800F0DB0_ovl11(X4_Obj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (--self->unk7C == 0) {
        self->unk5 = 5;
        self->unk6 = 0;
    }
}
