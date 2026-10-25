/* Shared body (DK-5), from the banked draft of func_800EF64C_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern int func_8002D760();
extern int func_8002D7A0();

void DEDUP_NAME(signed char* arg0) {
    if (arg0[4] == 4) {
        func_8002D7A0(arg0);
    } else {
        func_8002D760(arg0);
    }
}
