/* Shared body (DK-5), from the banked draft of func_800EEA80_ovl05 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F4844_ovl05[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800F4844_ovl05[*(signed char*)(arg0 + 4)](arg0);
}
