/* Shared body (DK-5), from the banked draft of func_800FA498_ovl47 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;

void DEDUP_NAME(Actor50* obj) {
    if (D_80091C44 == 0) {
        obj->step++;
    }
}
