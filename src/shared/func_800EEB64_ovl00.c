/* Shared body (DK-5), from the banked draft of func_800EEB64_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FA214_ovl00[])(u8*);

void DEDUP_NAME(u8* arg0) {
    D_800FA214_ovl00[*(signed char*)(arg0 + 5)](arg0);
}
