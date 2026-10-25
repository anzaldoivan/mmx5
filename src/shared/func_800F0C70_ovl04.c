/* Shared body (DK-5), from the banked draft of func_800F0C70_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern int func_8002D760();
extern int func_8002D6FC();

void DEDUP_NAME(signed char* arg0) {
    if (arg0[2] == 0) {
        func_8002D760(arg0);
    } else {
        func_8002D6FC(arg0);
    }
}
