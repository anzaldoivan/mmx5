/* Shared body (DK-5), from the banked draft of func_8004B1AC by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(s8* e) {
    if (e[2] == 0) {
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    DEDUP_CALLEE(e);
}
