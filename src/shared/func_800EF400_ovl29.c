/* Shared body (DK-5), from the banked draft of func_800EF400_ovl29 by tools/wave/gate.py rescan. */
#include "types.h"

extern int func_8002D760();
extern int func_8002D6FC();

void DEDUP_NAME(u8* arg0) {
    ((int*)arg0)[32] = 0;
    ((int*)arg0)[33] = 0;
    ((int*)arg0)[34] = 0;
    ((int*)arg0)[35] = 0;
    ((int*)arg0)[36] = 0;
    if (arg0[2] < 2) {
        func_8002D760(arg0);
    } else {
        func_8002D6FC(arg0);
    }
}
