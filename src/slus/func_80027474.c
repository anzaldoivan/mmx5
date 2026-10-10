/* T4 probe: u8 interpolation with unsigned divide (slus game_80013388). */
#include "types.h"

u8 func_80027474(u8 from, u8 to, u32 den, u32 t) {
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
