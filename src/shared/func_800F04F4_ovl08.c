/* Shared body (DK-5), from the banked draft of func_800F04F4_ovl08 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/rock_10/func_800F0434.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_27_dash_gunner.c:dash_gunner_explode, AGPL-3.0; proven shared with X6 by exact signature 7e98e0cffd71 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define M2C_UNK s32
M2C_UNK DEDUP_CALLEE(void*, M2C_UNK, M2C_UNK, M2C_UNK);

void DEDUP_NAME(Obj3EEC* self) {
    if (--self->unk7C == 0) {
        M2C_FIELD(self, s8*, 0x4) = 3;
    } else if (--self->unk7E == 0) {
        self->unk7E = 6;
        DEDUP_CALLEE(self, 1, 16, 16);
    }
}
