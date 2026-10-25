/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053828.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_main, AGPL-3.0; proven shared with X6 by exact signature f335fb55e436 (see THIRD_PARTY.md). */
#include "types.h"
extern void (*D_8007D9E0[])(X4_Obj*);
s32 func_80016490(s32, s32, void*);

void func_80057288(X4_Obj* self) {
    D_8007D9E0[self->unk5](self);
    if (self->unk18.bytes[2] == 0) {
        func_80016490(0, 0x13, 0);
        self->unk18.bytes[2] = 0x3C;
    } else {
        self->unk18.bytes[2]--;
    }
}
