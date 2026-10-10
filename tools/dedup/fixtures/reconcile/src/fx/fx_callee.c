/* Selftest callee (hand-written): r3 copies this definition's signature into the member's extern. */
#include "types.h"

void fx_callee(u8* o) {
    o[0] = 1;
}
