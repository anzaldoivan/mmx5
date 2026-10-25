/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800EA0DC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/misc/misc_01_common_effect.c:common_effect_animate, AGPL-3.0; proven shared with X6 by exact signature ed471c96b830 (see THIRD_PARTY.md). */
#include "types.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))
#define BASE_OBJECT(object) ((X4_Obj*)(object))
#define M2C_UNK s32
M2C_UNK func_80017248();
#define func_80017248 ((void (*)(X4_Obj*))func_80017248)
void func_8002D89C(X4_Obj*);

void func_800EF040_ovl10(Ent448C* self) {
    func_80017248(ANIMATED_OBJECT(self));
    if (self->unk45 != 0) {
        self->unk4 = 2;
    }
    func_8002D89C(BASE_OBJECT(self));
}
#undef func_80017248
