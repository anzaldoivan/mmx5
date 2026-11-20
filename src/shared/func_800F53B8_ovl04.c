/* Shared body (DK-5), from the banked draft of func_800F53B8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"
#define g_Player_as_Obj5864 (*(Obj5864*)&g_Player)

void DEDUP_NAME(Obj5864* obj) {
    DEDUP_CALLEE(obj);
    if (obj->unkE > g_Player_as_Obj5864.unkE) {
        if (obj->unkE - g_Player_as_Obj5864.unkE >= 9) {
            obj->unkE -= 2;
            goto end; // !FAKE: skips the second compare, as the target branches to the tail
        }
    }
    if (obj->unkE < g_Player_as_Obj5864.unkE) {
        if (g_Player_as_Obj5864.unkE - obj->unkE >= 9) {
            obj->unkE += 2;
        }
    }
end:
    if (--obj->unk7C == 0) {
        obj->unk6++;
    }
}
