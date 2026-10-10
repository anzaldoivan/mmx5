/* plateau.py --selftest plant: fixtures/target.c's shape with one load through s16; the selftest's target is this
 * file with `s16 *p` -> `u16 *p` (lh vs lhu: a WIDTH residual, labelled seed-structural). */
#include "types.h"

int fixture_fn(int a, int b, s16 *p) {
    if (a < b) {
        return a * *p + b;
    }
    return (a - b) * *p;
}
