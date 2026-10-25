/* Shared body (DK-5), from the banked draft of func_800F846C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void DEDUP_CALLEE(Ent846C*);

void DEDUP_NAME(Ent846C* arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk8;
    arg0->unk54 = 0;
    arg0->unk95 = 0x1E;
    arg0->unk90 = temp_v1;
    arg0->unk8C = temp_v1;
    DEDUP_CALLEE(arg0);
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk6++;
}
