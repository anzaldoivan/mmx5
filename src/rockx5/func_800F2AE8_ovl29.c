/* Dedup member (tools/dedup/propagate.py): cyclic rename, body inlined. */
#include "types.h"

#define DEDUP_NAME func_800F2AE8_ovl29

// dedup-inline ../shared/func_800F0240_ovl01.c
// dedup-rename func_8002D760 func_8002D7A0
// dedup-rename func_8002D7A0 func_8002D760
// dedup-rename func_800F0240_ovl01 func_800F2AE8_ovl29.NON_MATCHING

/* Shared body (DK-5), from the banked draft of func_800F2AE8_ovl29.NON_MATCHING by tools/wave/gate.py rescan. */
#include "types.h"

extern int func_8002D7A0();
extern int func_8002D760();

void DEDUP_NAME(signed char* arg0) {
    if (arg0[4] == 3) {
        func_8002D760(arg0);
    } else {
        func_8002D7A0(arg0);
    }
}
