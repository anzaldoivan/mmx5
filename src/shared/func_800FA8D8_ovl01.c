/* Shared body (DK-5), from the banked draft of func_800FA8D8_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

void DEDUP_NAME(Obj800FA8D8* arg0) {
    arg0->unk94 = 1;
    if (arg0->unk93 != 0) {
        arg0->unk5 = 5;
        arg0->unk6 = 0;
        return;
    }
    arg0->unk7C = 0x3C;
    arg0->unk6 = 1;
}
