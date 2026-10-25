/* Shared body (DK-5), from the banked draft of func_800EF718_ovl21 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800EFD34_ovl21[])(u8*);

void DEDUP_NAME(u8* arg0) {
    arg0[3] = 0;
    D_800EFD34_ovl21[*(signed char*)(arg0 + 4)](arg0);
}
