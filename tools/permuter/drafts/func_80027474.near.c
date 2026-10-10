/* T5.c1 permuter demo draft: our own near-miss of src/slus/func_80027474.c (swapped || operands, explicit
 * span temporaries). Compiles, does not match; the permuter searches from here. */
#include "types.h"

u8 func_80027474(u8 from, u8 to, u32 den, u32 t) {
    u32 span;

    if (den == t || from == to) {
        return from;
    }
    if (t == 0) {
        return to;
    }
    if (from > to) {
        span = from - to;
        return to + span * t / den;
    }
    span = to - from;
    return from + span * (den - t) / den;
}
