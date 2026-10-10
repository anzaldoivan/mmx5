/* Shared body (DK-5), from the banked draft of func_800EEF2C_ovl18 by tools/wave/gate.py rescan. */
#include "types.h"

extern s8 D_800D1C26;

void DEDUP_NAME(Obj* obj) {
    if (D_800D1C26 != 0) {
        obj->step++;
    }
}
