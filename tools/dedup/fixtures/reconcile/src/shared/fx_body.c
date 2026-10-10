/* Selftest shared body (hand-written, not game-derived): DEDUP_CALLEE is undeclared, so r3 must add its extern. */
#include "types.h"

void DEDUP_NAME(u8* o) {
    o[3] = 0;
    DEDUP_CALLEE(o);
}
