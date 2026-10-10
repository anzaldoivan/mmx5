/* plateau.py demo draft: src/slus/func_80027474.c with ONE type flip, `u8 to` -> `s8 to` (WIDTH residual: sll+sra 24 vs andi 0xFF, slt vs sltu). */
#include "types.h"

u8 func_80027474(u8 from, s8 to, u32 den, u32 t) {
    if (from == to || den == t) {
        return from;
    }
    if (t == 0) {
        return to;
    }
    if (to < from) {
        return to + (from - to) * t / den;
    }
    return from + (to - from) * (den - t) / den;
}
