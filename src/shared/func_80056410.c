/* Shared body (DK-5), from the banked draft of func_80056410 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_8007D5D4[])(signed char*);

void DEDUP_NAME(signed char* arg0) {
    if (D_8009A197 == 0) {
        D_8007D5D4[arg0[4]](arg0);
    }
}
