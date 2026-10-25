/* Selftest reloc-gated body (hand-written, not game-derived): fx_d_a is the rep's global; a member renames it. */
#include "types.h"

extern s32 fx_d_a;

void DEDUP_NAME(void) {
    fx_d_a = 1;
}
