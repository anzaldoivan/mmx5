/* Shared body (DK-5), from the banked draft of func_80046A6C by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void DEDUP_NAME(void* a0) {
    g_Player[0x98]--;
    g_Player[0x99]--;
    DEDUP_CALLEE(a0);
}
