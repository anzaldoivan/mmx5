/* Shared body (DK-5), from the banked draft of func_8002D078 by tools/wave/gate.py rescan. */
#include "types.h"

extern Obj8002CC08 D_80098120[];

Obj8002CC08* DEDUP_NAME(void) {
    Obj8002CC08* p;
    u8* q;
    s32 i;

    for (p = D_80098120; p < &D_80098120[32]; p++) {
        if (p->active == 0) {
            q = (u8*)p;
            for (i = sizeof(Obj8002CC08) - 1; i != -1; i--) {
                *q++ = 0;
            }
            p->unk50 = 0;
            p->unk54 = 0;
            p->unk68 = 0;
            return p;
        }
    }
    return 0;
}
