/* Shared body (DK-5), from the banked draft of func_800F0E78_ovl11 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_15/func_800EC378.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_51_fortress_cannon.c:fortress_cannon_lower_end, AGPL-3.0; proven shared with X6 by exact signature db765c44764d (see THIRD_PARTY.md). */
#include "types.h"
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

#define M2C_UNK s32
M2C_UNK func_80017248();
void DEDUP_NAME(X4_Obj* self) {
    ((void (*)())func_80017248)(ANIMATED_OBJECT(self));
    if (--self->unk7C == 0) {
        self->unk5 = 2;
        self->unk6 = 0;
        self->unk7C = 0x28U;
    }
}
