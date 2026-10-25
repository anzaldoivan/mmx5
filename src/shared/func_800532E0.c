/* Shared body (DK-5), from the banked draft of func_800532E0 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_8007BD4C[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_8007BD4C[*(signed char*)(arg0 + 6)](arg0);
}
