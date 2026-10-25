/* Shared body (DK-5), from the banked draft of func_800FA128_ovl40 by tools/wave/gate.py rescan. */
#include "types.h"

extern signed char D_8009A424;

void DEDUP_NAME(Ovl45State* arg0) {
    if (D_8009A424 == 0) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
