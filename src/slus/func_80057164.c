/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80053704.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_24_boss_warning.c:boss_warning_wait_tiles, AGPL-3.0; proven shared with X6 by exact signature f64138f8e32d (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern X4_Obj* D_800E95A8[22];

void func_80057164(X4_Obj* self) {
    X4_Obj* spawned;
    X4_Obj** entry;
    u32 index;
    s32 count;
    s32 expected;

    spawned = M2C_FIELD(self, X4_Obj**, 0x14);
    if (spawned->id != 4 || *(u16*)spawned == 0x400) {
        index = 0;
        count = 0;
        expected = 1;
        entry = D_800E95A8;
        do {
            if ((*entry)->unk5 == expected) {
                count++;
            }
            index++;
            entry++;
        } while (index < 0x16U);
        if (count == 0x16) {
            self->unk18.bytes[3] = 0;
            self->unk5++;
        }
    }
}
