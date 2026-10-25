/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80040304.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_76_spike_crawler.c:spike_crawler_hit_flash, AGPL-3.0; proven shared with X6 by exact signature 0f5c026ba0d7 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define BLINK_CLOCK(timer) (timer)

void func_80044C4C(X4_Obj* self) {
    if (self->unk6 == 0) {
        self->unk6++;
        M2C_FIELD(self, s8*, 0x61) = 0x28;
    }
    if (BLINK_CLOCK(M2C_FIELD(self, s8*, 0x61)) & 7) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--M2C_FIELD(self, s8*, 0x61) == 0) {
        self->unk5 = 1;
        self->unk6 = 0;
        self->unk42 &= 0x7FFF;
    }
}
