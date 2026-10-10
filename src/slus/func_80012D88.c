/* T4 probe: two fixed-count init loops (slus game_80011DC8, T3 outlier). */
#include "types.h"

extern s32 D_8006FC30[];

void func_80012D88(void) {
    LowMem* low = 0;
    /* null-based, not extern: the original builds both addresses with li/ori;
     * only a const words pointer keeps the counted second loop. */
    Slot* slots = 0;
    s32* const words = 0;
    Slot* s;
    s32 i;

    for (i = 0; i < 4; i++) {
        s = &slots[0x801F8100 / sizeof(Slot) + i];
        s->state = 0;
        s->work = (s32)&low->blk[i + 1];
        s->buf = 0x801FEC00 + i * 0x400;
        *(s32*)(s->work + 0x94) = 0x40000404;
        s->flag = 0;
    }
    for (i = 0; i < 9; i++) {
        words[0x801F8000 / 4 + i] = D_8006FC30[i];
    }
}
