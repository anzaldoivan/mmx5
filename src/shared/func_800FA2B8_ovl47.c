/* Shared body (DK-5), from the banked draft of func_800FA2B8_ovl47 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;

void DEDUP_NAME(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
