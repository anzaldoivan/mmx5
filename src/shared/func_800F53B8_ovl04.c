/* Shared body (DK-5), from the banked draft of func_800F53B8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj5864 D_8009A0A0;
extern void DEDUP_CALLEE(Obj5864*);

void DEDUP_NAME(Obj5864* obj) {
    DEDUP_CALLEE(obj);
    if (obj->unkE > D_8009A0A0.unkE) {
        if (obj->unkE - D_8009A0A0.unkE >= 9) {
            obj->unkE -= 2;
            goto end; // !FAKE: skips the second compare, as the target branches to the tail
        }
    }
    if (obj->unkE < D_8009A0A0.unkE) {
        if (D_8009A0A0.unkE - obj->unkE >= 9) {
            obj->unkE += 2;
        }
    }
end:
    if (--obj->unk7C == 0) {
        obj->unk6++;
    }
}
